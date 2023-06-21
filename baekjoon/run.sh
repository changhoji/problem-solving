num=$1
head=$(expr $num / 1000)

if [ $head -lt 10 ]; then
    cd 0$head
else
    cd $head
fi
cd $1
g++ solution.cpp
./a.out
