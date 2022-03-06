if [[ $# != 2 ]] #check whether the number of arguments is 2
then
	echo "Usage csv2html.sh <source_file> <destination_file>"
	exit 1

elif [[ ! -r $1 ]]
then
	echo "Error $1 is not a valid source file"
	exit 1
fi

echo "<TABLE>" > $2

sed -e 's+^+<TR><TD>+' -e 's+,+</TD><TD>+g' -e 's+$+</TD></TR>+' < $1 >> $2

echo "</TABLE>" >> $2

exit 0

