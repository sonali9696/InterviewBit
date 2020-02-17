int Solution::numSetBits(unsigned int A) {

    //string binaryNumber;
    int count = 0;
    
    while (A != 0)
    {
        //char bit = (A % 2) + '0';
        if(A % 2 == 1) count++;
        //binaryNumber = binaryNumber + bit;
        A /= 2;
    }
    
    return count;
    
    
}
