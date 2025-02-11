//int count;  // The result will be 3 because the variable wont be recreated. It's a GLOBAL variable it was never destroyed. It's visible to all the others files.
//static int count; // It is visible to this file only.

int increment(){

    static int count; // able to retain the value.
    count = count + 1;
    return count;
}
