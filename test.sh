#!/bin/bash

## -------------------------------- PATHS ----------------------------------- ##
ZAZVM=./VM/vm_champs/
USERVM=./VM
CHAMPSDIR=$ZAZVM/champs
## -------------------------------------------------------------------------- ##

## -------------------------------- TESTS ----------------------------------- ##
## PUT 0 IF YOU DON'T WANT TO TEST
TESTSOLOCHAMPS=0
TESTSBATTLE=1
## -------------------------------------------------------------------------- ##

## -------------- CHAMPS TO TEST (comment what you don't want) -------------- ##
## !! CHAMPS SHOULD BE IN CHAMPSDIR OR IN CHAMPSDIR/examples
CHAMPS[0]=Gagnant
CHAMPS[1]=Octobre_Rouge_V4.2
CHAMPS[2]=ex
CHAMPS[3]=first
CHAMPS[4]=jumper
CHAMPS[5]=maxidef
CHAMPS[6]=mortel
CHAMPS[7]=slider2
CHAMPS[8]=toto
CHAMPS[9]=bigzork
CHAMPS[10]=fluttershy
CHAMPS[11]=helltrain
CHAMPS[12]=turtle
CHAMPS[13]=zork
## -------------------------------------------------------------------------  ##

SCRIPTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
TESTSDIR=$SCRIPTDIR/TEST
MKDIR=/bin/mkdir

## --------------------------------- START ---------------------------------- ##
if [ ! -f $USERVM/corewar ]; then
	echo -e "No corewar executable found in\033[1;32m" $USERVM "\033[mdid you forget to \033[1;35mmake\033[m or change the \033[1;35mUSERVM\033[0m path in script ?"
	exit 1
fi
if [ ! -f $ZAZVM/corewar ]; then
	echo "No corewar executable found at\033[1;32m" $ZAZVM/corewar "\033[m you can change \033[1;35mZAZVM\033[0m path in script"
	exit 1
fi

if [ ! -d $TESTSDIR ]; then
	$MKDIR $TESTSDIR
fi

i=0
for element in ${CHAMPS[@]}
do
	if [[ $TESTSBATTLE == 0 && $TESTSOLOCHMAPS == 0 ]]; then
		break
	fi
	CHAMP_PATH=$CHAMPSDIR/$element
	if [ ! -f $CHAMP_PATH.s ]; then
		CHAMP_PATH=$CHAMPSDIR/examples/$element
	fi
	if [ ! -f $CHAMP_PATH.s ]; then
		((i++))
		continue
	fi
	if [ ! -f $CHAMP_PATH.cor ]; then
		$ZAZVM/asm $CHAMP_PATH.s >&-
	fi
	CHAMPS_PATH[i]=$CHAMP_PATH
	((i++))
done


for element in ${CHAMPS[@]}
do
	if [[ $TESTSOLOCHAMPS == 0 ]]; then
		break
	fi
	## print element name ##
	echo -en "- " $element
	LENGTH=${#element}
	if [[ $LENGTH -lt 5 ]]; then
		echo -en "\t"
	fi
	if [[ $LENGTH -lt 14 ]]; then
		echo -en "\t"
	fi
	if [[ $LENGTH -lt 27 ]]; then
		echo -en "\t"
	fi
	echo -en "\t"

	CHAMP_PATH=$CHAMPSDIR/$element
	if [ ! -f $CHAMP_PATH.s ]; then
		CHAMP_PATH=$CHAMPSDIR/examples/$element
	fi
	if [ ! -f $CHAMP_PATH.s ]; then
		continue
	fi

	## create zaz file ##
	if [ ! -f $TESTSDIR/zaz_file_$element ]; then
		$ZAZVM/corewar -v 31 $CHAMP_PATH.cor > $TESTSDIR/zaz_file_$element
	fi

	## create user file ##
	$USERVM/corewar -v 31 $CHAMP_PATH.cor > $TESTSDIR/user_file_$element

	## create diff ##
	diff $TESTSDIR/user_file_$element $TESTSDIR/zaz_file_$element > $TESTSDIR/diff_$element

	## print ok or bad from the return of the diff command ##
	if [[ $? == 0 ]]; then
		echo -en " [\033[1;35m√\033[m]\n"
	else
		NB_DIFF="$( cat $TESTSDIR/diff_$element | wc -l)"
		echo -en " [\033[0;31mX\033[m] "
		echo $NB_DIFF "diff(s) in" $TESTSDIR/diff_$element
	fi
done

if [[ $TESTSBATTLE -ne 0 ]]; then
	TIT="-"
	BATTLENAME=${CHAMPS[0]}$TIT${CHAMPS[4]}$TIT${CHAMPS[6]}$TIT${CHAMPS[6]}
	echo -en "- " $BATTLENAME
	LENGTH=${#BATTLENAME}
	if [[ $LENGTH -lt 5 ]]; then
		echo -en "\t"
	fi
	if [[ $LENGTH -lt 14 ]]; then
		echo -en "\t"
	fi
	if [[ $LENGTH -lt 27 ]]; then
		echo -en "\t"
	fi
	echo -en "\t"

	## create zaz file ##
	if [ ! -f $TESTSDIR/zaz_file_$BATTLENAME ]; then
		$ZAZVM/corewar -v 1 ${CHAMPS_PATH[1]}.cor ${CHAMPS_PATH[4]}.cor ${CHAMPS_PATH[6]}.cor ${CHAMPS_PATH[7]}.cor > $TESTSDIR/zaz_file_$BATTLENAME
	fi

	## create user file ##
	$USERVM/corewar  ${CHAMPS_PATH[1]}.cor ${CHAMPS_PATH[4]}.cor ${CHAMPS_PATH[6]}.cor ${CHAMPS_PATH[7]}.cor > $TESTSDIR/user_file_$BATTLENAME
		
	## create diff ##
	diff $TESTSDIR/user_file_$BATTLENAME $TESTSDIR/zaz_file_$BATTLENAME > $TESTSDIR/diff_$BATTLENAME

	## print ok or bad from the return of the diff command ##
	if [[ $? == 0 ]]; then
		echo -en " [\033[1;35m√\033[m]\n"
	else
		NB_DIFF="$( cat $TESTSDIR/diff_$BATTLENAME | wc -l)"
		echo -en " [\033[0;31mX\033[m] "
		echo $NB_DIFF "diff(s) in" $TESTSDIR/diff_$BATTLENAME
	fi
fi
