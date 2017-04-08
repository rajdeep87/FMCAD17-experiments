PWD=`pwd`
TIMEOUT=2000
TOOL=acdlp
BENCHMARKDIRS=`cat benchmarks.txt`
PROGRESSLOG=${PWD}/progress.log-${TOOL}
FLAGS="--verbosity 10 --acdl --decision ordered --learning first-uip --propagate chaotic --inline --unwind 1" 
EXEC=/users/rajdeep/acdlp/2ls/src/2ls/2ls
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
