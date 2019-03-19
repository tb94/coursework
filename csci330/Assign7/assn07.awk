BEGIN {
    FS=","
    split( "Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec", mName, ",")
    mCost[11] = 0
}

{
    if ($1 == "")
    {
        debitSum += $5
    }
    if ($1 !="")
    {
        checkSum += $5
    }

    if (!($3 in categoryArray))
    {
        categoryArray[$3] == $5
    }
    if ($3 in categoryArray)
    {
        categoryArray[$3] += $5
    }

    mon = substr($2, 6, 2)
    num = sprintf("%d", mon)
    
    if (mCost[num] < 0)
        mCost[num] = $5
    if (mCost[num] >=0)
        mCost[num] += $5
}

END {
    printf ("Checks and Debits\n")
    printf ("Checks%20.2f \n", checkSum)
    printf ("Debits%20.2f \n", debitSum)
    
    printf ("\nExpenses by Category\n")
    for (category in categoryArray)
		printf ("%-18s %.2f \n", category, categoryArray[category])

    printf ("\nExpenses by Date\n")
    for (m in mName)
        printf ("%-18s %.2f \n", mName[m], mCost[m])
}
