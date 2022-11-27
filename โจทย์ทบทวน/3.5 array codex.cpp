#include <stdio.h>

int main ()
{
  int length , count , rp , i , x ,y ;										//lenght = userInput,count = count number repeat , rp && i && x = storage data
  
  // user input number
  printf( " input number of element to be store in array : " );			//user insert number
  scanf( "%d" , &length ) ;												//college data , Lenght	
  printf( " \n------------------------------------------------\n" ) ; 

  int array[length] ;													//store length in array
  
   // for loop Array[1] , input number
  for (int i = 0 ; i < length ; i++ )									//show array[1] Loop follow by lenght
  {
    printf( " array[%d] = " , i+1 ) ;									// print array[1] start at 1 because i+1
    scanf( "%d" , &array[i] ) ;											//college data , array[i]	
  }	//end for lopp array[1]
  
  /*result  array[1] = x
  			array[2] = x
  	   		array[3] = x
  	   		array[4] = x
  	   		array[n] = x
  */
  // go to fine X at 31
  printf( "\n------------------------------------------------\n" ) ;
	
  //counting repeat number or fine X
  for( int x = 0 ; x < length ; x++ )									// loopfor counting numbrt repeat follow by lenght			
  {									
  		count = 1 ;														//set count = 1						
        for( int rp = x+1 ; length - 1 >= rp ; rp++ )					//loopfor rp= repeat
		{						
            if( array[x] != 0 && array[rp] == array[x] )				//start condition if
			{			
                count++ ;												
                array[rp] = 0;								
				break;	
																
            } // endif
        } // endfor
        //Print output
        if( array[x] > 0 ){
            printf( "%d -> %d \n" , array[x] , count ) ;				// print result 
        } // endif 
    } // endfor	 
    return 0;
}
