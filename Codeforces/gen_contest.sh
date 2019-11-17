contest_name=$1
mkdir $contest_name
cd $contest_name

cp ../../tmp.cpp A.cpp
cp ../../tmp.cpp B.cpp
cp ../../tmp.cpp C.cpp
cp ../../tmp.cpp D.cpp
cp ../../tmp.cpp E.cpp

cp ../../stress.sh .
cp ../../testlib.h .
cp ../../gen.cpp .

echo "Done! GoodLuck Sir \")))"