WA=$1
AC=$2
gen=$3

# First param is {Wrong Answer} executable
# Second param is {Correct Answer} executable
# Third param is the {Generator}

i=1

# for((i = 1; ; ++i)); do

while true
do
    echo $i
    ./$gen $i > test
    ./$WA < test > out1
    ./$AC < test > out2
    diff -w out1 out2 || break
    # diff -w < ( ./$WA < test) < ( ./$AC < test) || break
    i=$(( $i + 1 ))
done