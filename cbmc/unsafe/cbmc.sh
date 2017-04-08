PWD=`pwd`
TIMEOUT=18000
#DIRS=`ls -l $MYDIR | egrep '^d' | awk '{print $9}'`
TOOL=cbmc
BENCHMARKDIRS=`cat benchmarks.txt`
PROGRESSLOG=${PWD}/progress.log-${TOOL}
FLAGS="--no-sat-preprocessor --unwind 10 --no-unwinding-assertions"
EXEC=/users/rajdeep/cbmc-git/cbmc/src/cbmc/cbmc
echo "Starting experiments at `date` on `hostname`" > ${PROGRESSLOG}
for DIR in $BENCHMARKDIRS
do
  echo  ${DIR}
  cd ${DIR}
  filename=main.c
  echo "Starting to processing $DIR/$filename at `date`" >> ${PROGRESSLOG}
  runsolver -C $TIMEOUT -W $TIMEOUT -d 1 -M 32768 ${EXEC} ${FLAGS} $filename >> ${PROGRESSLOG}
  echo "done at `date`" >> ${PROGRESSLOG}
  cd ../
done
