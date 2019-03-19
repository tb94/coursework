#!/bin/bash

	ans="";

	while [ "$ans" = "" ]
	do
		select choice in Relist `ls $HOME/junk` Quit
   	    do
      	    echo "$choice"
      	    if test -n $choice
      	    then
         	    break
      	    fi
   	    done

		if [ "$choice" = "Quit" ]
		then
			break

		elif [ "$choice" = "Relist" ]
		then
			continue
		fi

        newChoice=`echo $choice | sed 's/.....-...-..-..-..//'`

	    if `ls | grep "$choice"` [ $? = "1" ]
	    then
		    mv $HOME/junk/$choice ./$newChoice
	    else
	        opt = ""
    		while [ "$ans" != "o" || "$ans" != "c" || "$ans" != "m" ]
		    do
			    echo "The file already exists"
			    echo "Overwrite, Cancel, or Move anyway? (o/c/m)"
			    read $opt
			    case "$opt" in
				o )
                    mv $HOME/junk/$choice ./$newChoice
                    ;;
				c )
                    break
                    ;;
				m )
			      mv $HOME/junk/$choice ./	
                  ;;
				* )
                    continue
			    esac
		    done
	    fi
    done

