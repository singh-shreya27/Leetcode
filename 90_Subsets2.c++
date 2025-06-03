          //Subsets-2


//brute force :
//put all the 2^n subsets into a set (list<list>) ..so that all the duplicates will go away.
//After recursion, we are an extra time of converting it into a set and then reconverting it back into a list<list>
//If you are putting every element into the set ..it's gonna take mlogm where m=2^n (size of set).

//so optimise the recursion.
