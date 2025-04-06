#include <iostream>
#include <stdlib.h>
#include "stdlib.h"
#include <ctype.h>
#include "math.h"

typedef int* IntArrayPtr;

//***********Function Prototypes**********


void fill_array(int a[], int SizeOfArray);

int GetArraySize();

void display_array(int a[], int SizeOfArray);

void BubbleSort(int NumArray[], int SizeOfArray);

void MergeSort(int NumArray[], int first, int last);

void QuickSort(int NumArray[], int first, int last);

void HeapSort(int NumArray[], int SizeOfArray);

int  GetSortingChoice();

//**FUNCTIONS USED FOR HEAPSORT**

int Parent(int i);

int LeftChild(int i);

int RightChild(int i);

void BuildMaxHeap(int NumArray[], int SizeOfArray);

void MaxHeapify(int NumArray[], int SizeOfArray, int index);

int Partition(int NumArray[], int first, int last);

void Merge(int NumArray[], int first, int middle, int last);


//*********Main*********
using namespace std;

int main()
{

char done = '\0';

do
{

  //Variable Declarations
	  int ArraySize = 0;  //Stores the size of the array
      IntArrayPtr a;

      int MenuChoice = 0;
	  int first = 0;
	  int last = 0;
	
	

	 //Get Size of the array
		 ArraySize = GetArraySize();


    //@@@Dynamically declare data array@@@
              a = new int[ArraySize];
     
		//Fill the array with random numbers.
				fill_array(a, ArraySize);

    //Display the array
				display_array(a, ArraySize);

    //Get users choice for Sorting 
       MenuChoice = GetSortingChoice();

     //Use appropriate menu choice set to sorting algorithm.
        switch (MenuChoice)
		{
	   
		 case 1:
            
              //Use **Bubble Sort to Sort the Array**
                 BubbleSort(a, ArraySize);
				 break;
	    
 		case 2:

	          first = 0;
              last = ArraySize - 1;

		    //Use **MergeSort Sort to Sort the Array**
                  MergeSort(a, 0, last);
		          break;
	   
		case 3:
	         //Use **Quick Sort to Sort the Array**
                 	 first = 0;
                 	 last = ArraySize - 1;
    
                      QuickSort(a, first, last);
		    	      break;
		case 4:
	           //Use **Heap Sort to Sort the Array**
                  HeapSort(a, ArraySize);
		     
	                break;
		default:
	    
               cout<<"\nError Now Exiting!!";
		       exit(1);
        
		} //end of switch
	



    cout<<"\n     THE ARRAY HAS BEEN SORTED  \n\n";

	 //Display the sorted array
         display_array(a, ArraySize);



delete [] a;

cout<<endl<<endl<<"If you would like to run again enter Y followed by <ENTER>: ";
cin>>done;

done = toupper(done);

cout<<endl<<endl<<endl;

}while (done == 'Y');

cout<<endl<<endl<<"Goodbye";

return 0;
}//end of main



//***********Function Definitions**********8


//**Fill Array**
void fill_array(int a[], int SizeOfArray)
{

	//Variables
    int RandomFillNum;

  //Loop for filling array with Random numbers.
		for(int index = 0; index < SizeOfArray; index++)
		{
         
			//initialize RandomFillNum
			   RandomFillNum = 0;

			//Calculate next random number to be created.
           RandomFillNum = rand();

			   a[index] = RandomFillNum;
       

		}
}//end fill_array




//**Get Array Size**
int GetArraySize()
{
 //Variable Declarations
	 int Asize;

	cout<<"Enter the size of the array to be sorted:  ";
	cin>>Asize;
  cout<<"\n\n";

	return Asize;
} //end get arraysize

//**Display Array Size**
void display_array(int a[], int SizeOfArray)
{
    //variable declarations
	     char YesNo;
       

  	//For Testing Purposes 
      cout<<"\n\nIf you would like the array to be diplayed enter Y,\n any other entry is considered a No: ";
			cin>>YesNo;

      YesNo = toupper(YesNo);

		if (YesNo == 'Y')
		{
			for (int index = 0; index<SizeOfArray;index++)
			{

            cout<<"\n"<<a[index];

			}

          cout<<"\n\n End of the Array of size: "<<SizeOfArray<<endl;
					cout<<"     Hit any key to continue: ";
					cin>>YesNo;
		}
      

		  

}//end of display_array



//		**Definition Function BubbleSort**
void BubbleSort(int NumArray[], int SizeOfArray)
{

   //variable declarations
	   int temp = 0;


    for (int OuterIndex = 1; OuterIndex < SizeOfArray; OuterIndex++)
		{

         for(int CompIndex = SizeOfArray - 1; CompIndex >= OuterIndex; CompIndex--)
				 {
              
					   //check and swap adjacent array indexes
					     if(NumArray[CompIndex - 1] > NumArray[CompIndex]) 
							 {
                     //exchange elements
									      temp = NumArray[CompIndex - 1];

											
											   NumArray[CompIndex - 1] = NumArray[CompIndex];

												 NumArray[CompIndex] = temp;

							 }//if statement


				 }//inner for loop


		}//outer for loop


} //end of BubbleSort



//		**Definition Function MergeSort**
void MergeSort(int NumArray[], int first, int last)
{

   
 //check to see if first is smalller than last
	if(first < last)
	{

     //index of middle value
	  
	     int middle = (first + last)/2;

          MergeSort(NumArray, first, middle);
	      MergeSort(NumArray, middle + 1, last);
	        
          Merge(NumArray, first, middle, last);

	}



}//end of MergeSort


//		**Definition Function QuickSort**
void QuickSort(int NumArray[], int first, int last)
{

	int q = 0;

 //check to see if you have reached the end
	if (first < last)
	{

       q =  Partition(NumArray,first,last);

	   //Call Quicksort on remaining partitions recursively
	      QuickSort(NumArray, first,q - 1);
		  QuickSort(NumArray, q + 1, last);

	}
	
     


}//end of QuickSort


//		**Definition Function HeapSort**
void HeapSort(int NumArray[], int SizeOfArray)
{

  //Data

  //Build Max Heap
	BuildMaxHeap(NumArray, SizeOfArray);

  //Sort the array
	for (int i = SizeOfArray; i >= 2; i--)
	{

       int temp;

	   //exchange root with NumArray[i]
		 temp = NumArray[0]; 
         NumArray[0] = NumArray[i-1];
		 NumArray[i-1] = temp;

       //update heap size
         SizeOfArray = SizeOfArray - 1;


	   //Call Max Heapify to resort
		 MaxHeapify(NumArray, SizeOfArray, 0);


	}


}//end of HeapSort


//	      **Definition GetSortingChoice**

int  GetSortingChoice()
{
  //Variables
    int choice = 0;
    bool ValidEntry = true;

  //Display Menu for user to choose sorting algorithm

 do 
   {
   	 cout<<"\n\n Choose from the following  Sorting algorithms: ";
   	 cout<<"\n\t 1 - Bubble Sort";
   	 cout<<"\n\t 2 - Merge Sort";
   	 cout<<"\n\t 3 - Quick Sort";
   	 cout<<"\n\t 4 - Heap Sort";

   	 cout<<"\n Enter the number of you choice then hit <ENTER>: ";
   	 cin>>choice;
    
   	 if ((choice < 1) || (choice > 4))
      	 {
      	   ValidEntry = false;
		 cout<<"\n\n\t INVALID ENTRY TRY AGAIN";
        
		}
     else
		 ValidEntry = true; 

     } while (ValidEntry == false);


     return choice;

} //end of GetSortingChoice



//**HEAP SORT FUNCTION DEFINITIONS***

int Parent(int i)
{

	int conv = 0;

	conv = i + 1;

	conv = floor(conv/2);

	return (conv - 1);


}//END OF PARENT

int LeftChild(int i)
{

	int conv = 0;

	conv = i + 1;

	conv = 2 * conv;

	return (conv - 1);


}//END OF LEFT CHILD

int RightChild(int i)
{

	int conv = 0;

	conv = i + 1;

	conv = (2*conv) + 1;

	return (conv - 1);


}//END OF RIGHT CHILD

void BuildMaxHeap(int NumArray[], int SizeOfArray)
{

    //Variables
	   int i = 0;
       int conv = 0;

   

	//for loop going down to the root
        //initialize i
	      i = floor(SizeOfArray/2);

		do
		{

            conv = i;
			conv = conv - 1; 

			MaxHeapify(NumArray, SizeOfArray, conv);

			i--;

		}while (i>=1);


}//END OF BUILD MAX HEAP

void MaxHeapify(int NumArray[], int SizeOfArray, int index)
{

//Data Variables
	int left;
	int right;
    int largestindex;
    int temp;

   //set left value to the left child of index
     left = LeftChild(index);
   //set right value to the right child of index
     right = RightChild(index);

   //Compare the value of left child with index
      if ((left <= (SizeOfArray-1)) && (NumArray[left] > NumArray[index]))
	  {
            
		  largestindex = left;

	  }
      else
	  {

           largestindex = index;

	  }


    //Compare the value of Right Child with index
  if ((right <= (SizeOfArray - 1)) && (NumArray[right] > NumArray[largestindex]))
	  {
            
		  largestindex = right;

	  }
     


	//If the largest index is not equal to i then exchange with largest
  if(largestindex != index)
  {
     //swap values
	   temp = NumArray[index];

	   NumArray[index] = NumArray[largestindex];
      
	   NumArray[largestindex] = temp;
       

  //Call max heapify again
    MaxHeapify(NumArray, SizeOfArray, largestindex);


  }



}//END OF max heapify

//**********END OF HEAP FUNCTION DEFINITIONS*******



int Partition(int NumArray[], int first, int last)
{


//Data
	int LessDiv;
	int CompValue;
    int temp;
	int currIndex = 0;

	CompValue = NumArray[last];

    LessDiv = first - 1; //initialize partdiv.

    //initialze CurrIndex
	  currIndex = first;

   //go from beggining to one less than the last element.
	for(currIndex; currIndex < last; currIndex++)
	{

       //If NumArray[currindex] is less than the compare value
		  if (NumArray[currIndex] <= CompValue)
		  {

              //increase LessDiv
			     LessDiv = LessDiv + 1;

			  //Swap current index with LessDiv
				 temp =  NumArray[currIndex];


			      NumArray[currIndex] = NumArray[LessDiv];

				  NumArray[LessDiv] = temp;
				  
		  }
	 
	}

           //Exchange LessDiv + 1  with CompValue
             temp = NumArray[LessDiv + 1];
			 NumArray[LessDiv + 1] = NumArray[last];

			 NumArray[last] = temp;


	       //return index of middle value

			 return (LessDiv + 1);
           


}//*************end of partition****************



void Merge(int NumArray[], int first, int  middle, int last)
{


//Merge version 2
	int size = last - first +1,
		mid = (first + last)/2;

    
	IntArrayPtr TempA;

	TempA = new int[size];

    int count = 0;


	for (int x = first; x<=mid; x++,count++)
	{
              
       TempA[count] = NumArray[x];

	}

    for(int x2=last;x2>=mid+1;x2--, count++)
	{

        TempA[count] = NumArray[x2];

	}

	for(int x3=0, y = size-1, put = first;x3<=y;put++)
	{

         //check values in array swap if necessary
		   if(TempA[x3] <= TempA[y])
		   {

              NumArray[put] = TempA[x3];
			  x3++;

		   }

           else
		   {
				NumArray[put] = TempA[y];
				y--;
		   }

	}
    
	delete [] TempA;


}// END OF MERGE



