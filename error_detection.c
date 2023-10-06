/*
 * Spotting The Hacker
 *
 * Author: Hasan Zaidi



detect errors in the transmissions from the White House to 
the United Nations.

The White House is highly aware that there are a number of different ways to go about detecting errors in 
a transmission data stream. They are not yet sure which technique they want to use. That’s why they have 
asked you to implement three different error detection algorithms so that they can study how they 
perform and then pick one to move forward with.

*/



#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/wait.h>



int vert_parity_check(int *binArrByte, int *new_byte_array_horiz){
  
  for(int i = 0; i <= 8; i++){
    for(int j = 0; j <= 8; j++){
      new_byte_array_horiz[j] = binArrByte[i];
      continue;
    }
  }
}


int checkSum(int *binArray, int length) {
    int sum = 0;

    // Calculate the running sum of the array elements
    for (int i = 0; i < length; i++) {
        sum += binArray[i];
    }
    return sum;
}



void convertToBin(int decVal, int* arr) {
  int index;
  if (decVal <= 255){
    index = 7;  // Start from the rightmost (least significant) bit
  } else {
    index = 15;
  }
    
    if (decVal > 255) {
      for (int i = 0; i < 15; i++) {
        arr[i] = 0;
      }
    } else {
      for (int i = 0; i < 8; i++) {
        arr[i] = 0;
      }
    }

    // Initialize the array to all zeros
    

    while (decVal > 0 && index >= 0) {
        arr[index] = decVal % 2;  // Store the remainder (binary digit)
        decVal /= 2;              // Update the decimal value
        index--;                  // Move to the next array element
    }
}



int amntOf1s(int *ByteArray){
  int amntOf1s = 0;
  for(int i = 0; i <= 7; i++){
    if(ByteArray[i] == 1){
      amntOf1s++;
    }
  }
  return amntOf1s;
}


bool isItEven(int total1s){
  if(total1s % 2 == 0){
    return true;
  }else{
    return false;
  }
}


int ParityCheck(char EvenorOdd){
  int eighthBitVal = 0;
  if(EvenorOdd == 'E'){
    eighthBitVal = 0;
  } if(EvenorOdd == 'O'){
    eighthBitVal = 1;
  }
  return eighthBitVal;
}


int main(void) {

  
  FILE *parity = fopen("White House Transmission Data - Parity.txt", "r");
  FILE *checkSum = fopen("White House Transmission Data - Checksum.txt", "r");
  FILE *twoDParity = fopen("White House Transmission Data - 2D Parity.txt", "r");

  int i;

  



  int binArrByte[9] = {0,0,0,0,0,0,0,0,0};
  int binArrByte1[9];
  int parityArray[5][9];
  int checkSumArray[5][9];
  int new_byte_array_horiz[8];
  int twoD_parity_array[44][10];
  int n;

  //Reading and loading up the checksumarray
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 9; j++) {
      fscanf(checkSum, " %d", &n);
      checkSumArray[i][j] = n;
    }
  }

  //Checksum===============
  //Using methods to manipulate loaded values of checksumarray
  printf("\nCheck Sum Method----\n\n\n");
  for (int i = 0; i < 5; i++) {
    printf("Data Stream: \n");
    int summ = 0;
    for (int j = 0; j < 9; j++) {
      convertToBin(checkSumArray[i][j], binArrByte);
      if(j != 8){
        printf("%4d  ", checkSumArray[i][j]);
        summ += checkSumArray[i][j];
        }
      if(j==8){
        printf("Checksum: %d \n", checkSumArray[i][j]);
        printf("Sum of data items: %d",summ);
        printf("\nBinary of Checksum: ");
        for(int l = 0; l < 8; l++){
          printf("%d", binArrByte[l]);
        }
        printf("\nBinary of Summed Data: ");
        for(int l = 0; l < 11; l++){
          convertToBin(summ, binArrByte1);
          printf("%d", binArrByte1[l]);
        }
      } 
      if(j!=8){
        for(int z=0; z < 8; z++){
        printf("%d",binArrByte[z]);
        }
      }
      //Resetting the Binary array for all binaries except the longer byte
      for(int z = 0; z < 9; z++){
        binArrByte[z] = 0;
      }
      for(int z = 0; z < 11; z++){
        binArrByte1[z] = 0;
      }
      printf("\n\n");
    }
  }
  

  //Reading and loading up the parityArray 
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 9; j++) {
      fscanf(parity, " %d", &n);
      parityArray[i][j] = n;
    }
  }

  printf("\n\nParity Check----\n\n\n");


  //PARITY Check===============
  int eightthBitVal;
  
  for (int i = 0; i < 5; i++) {
    printf("\nData Stream: \n\n");
    
    for (int j = 0; j < 8; j++) {
      convertToBin(parityArray[i][j], binArrByte);
      if(isItEven(amntOf1s(binArrByte))==true){
        eightthBitVal = ParityCheck('E');
      }else{
        eightthBitVal = ParityCheck('O');   //Holds the eighth bit val for each item
      }
      
      for(int z=0; z < 8; z++){
        printf("%d",binArrByte[z]);
      }
      printf("%4d \n", parityArray[i][j]);
      //parity byte stuff
      //If the amnt of 1's is even and the parity bit is 0 then failed========
      if((isItEven(amntOf1s(binArrByte)) == true)&&(eightthBitVal == 0)){
        printf("PASSED\n\n");
      } else {
        printf("FAILED\n\n");
      }
      if(j==7){
        int eightthbitval;
        //feeding in the parity decimal value and the binary array with deafults of 0
        convertToBin(parityArray[i][8],binArrByte);
        printf("Amnt of 1's: %d", amntOf1s(binArrByte));
        if(isItEven(amntOf1s(binArrByte))==true){
          eightthbitval = ParityCheck('E');
        }if(isItEven(amntOf1s(binArrByte))==false){
          eightthbitval = ParityCheck('O');}
        printf("\nParity Byte: %d\n\n", eightthbitval);
      }
      
   
      //resetting the binary array to default of 0's
      for(int k = 0; k < 9; k++){
        binArrByte[k]=0;
      }
    }
    printf("\n");
  }




  //Reading and loading up the 2D parity array
  for (int i = 0; i < 44; i++) {
    for (int j = 0; j < 10; j++) {
      fscanf(twoDParity, " %d", &n);
      twoD_parity_array[i][j] = n;
    }
  }


  //2D Parity Check===============
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 10; j++){
      convertToBin(twoD_parity_array[i][j], binArrByte);
    }
    printf("%d\n",binArrByte[i]);
  }

  for(int i = 0; i < 9; i++){
    binArrByte[i]=0;
  }

  for(int i = 0; i < 9; i++){
    
  }

  

  printf("\n\n");



  
  return 0;

  
}

