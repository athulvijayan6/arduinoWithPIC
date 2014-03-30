mkdir $1
mkdir $1/libraries
cp .createpic/library.h $1/libraries
mv $1/libraries/library.h $1/libraries/$1.h
sed -i "s/ATHUL_PIC_LIBRARY/ATHUL_PIC_LIBRARY_$1/g" $1/libraries/$1.h
cp .createpic/library.c $1/libraries
mv $1/libraries/library.c $1/libraries/$1.c
sed -i "s/library/$1/g" $1/libraries/$1.c
cp .createpic/main.c $1/
sed -i "s/library/$1/g" $1/main.c

if [[ $2=="xc16" ]]; then
	cp .createpic/compile.sh $1/
	chmod +x $1/compile.sh
fi