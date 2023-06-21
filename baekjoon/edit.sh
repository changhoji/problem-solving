num=$1
head=$(expr $num / 1000)

if [ $head -lt 10 ]; then
    if [ ! -d ./0$head ]; then
        mkdir 0$head
    fi
    cd 0$head
else
    if [ ! -d ./$head ]; then
        mkdir $head
        echo "hi.."
    fi
    cd $head
fi

if [ ! -d ./$1 ]; then
    mkdir $1
fi
cd $1

code solution.cpp
