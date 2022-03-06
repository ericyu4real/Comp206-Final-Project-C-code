if [[ $# != 2 ]] #check whether the number of arguments is 2
then
	echo "Usage fixformat.sh <dirname> <opfile>"
	exit 1

elif [[ ! -d $1 ]]
then
	echo "Error $1 is not a valid directory"
	exit 1
fi

#use find to look for any matched files under given directory
csv_files=$(find $1 -name '[lL][aA][bB]-[abcdefghiABCDEFGHI].csv')
output_file=$2
echo "User Email,Name (Original Name),Lab,Total Duration (Minutes)" > $output_file #clear the content of output file or create an output file

for file in $csv_files
do
	num=$(echo "$file" | awk 'BEGIN {FS="-"} {if($NF=="a.csv"||$NF=="A.csv"){print "A"}} {if($NF=="b.csv"||$NF=="B.csv"){print "B"}} {if($NF=="c.csv"||$NF=="C.csv"){print "C"}} {if($NF=="d.csv"||$NF=="D.csv"){print "D"}} {if($NF=="e.csv"||$NF=="E.csv"){print "E"}} {if($NF=="f.csv"||$NF=="F.csv"){print "F"}} {if($NF=="g.csv"||$NF=="G.csv"){print "G"}} {if($NF=="h.csv"||$NF=="H.csv"){print "H"}} {if($NF=="i.csv"||$NF=="I.csv"){print "I"}}') #determine the lab
	awk -v i=$num 'BEGIN {FS=","} {if(NF==6 && $1!="Name (Original Name)"){print $2","$1","i","$5}} {if(NF==4 && $1!="Name (Original Name)"){print $2","$1","i","$3}}' $file >> $output_file
done
