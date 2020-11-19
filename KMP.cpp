//fills an array with a longest possible prefix/ suffix for a given pattern
void getLPS(){

    //set length to 0

    //probably while i < some value j (j being the pattern we'll take in as a param)
        //if pattern[i] = pattern[length]
            //increment length
            //append length
            //increase i
        //else
            //if the legth isn't empty
                //set length to last element of the array
            //else
                //catch edge
}

void KMP(){

    //create a longest possible pre/suffix array the side of the pattern
    //call getLPS

    //set index i for text iteration
    //set index j for pattern iteration

    //while text iteration < length of text
        //if the pattern[j] == text[i]
            //increase both iters

        //if pattern[j] is equal to the length of text
            //match found
            // set j to last lps element

        //else if there's a mismatch
            //if j isn't 0
                //set j to last lps element
            //else
                //increment i


}