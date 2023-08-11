#include <stdio.h>
#include <ctype.h>
#include <math.h> 
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h> 

bool translated=false; 

void translate(char word[]){
  bool vowel_passed=false;
  bool capitalized=false;
  char substr[100];
  int index1=0;

  char modified[100];
  int index=0; 

  if (isupper(word[0])){
    capitalized=true;
    word[0]=tolower(word[0]);  
  }

  for (int i=0; i<(int) strlen(word); i++){
     if (((word[i]=='y' && i!=0) || word[i]=='a' || word[i] =='e' || word[i]=='i' || word[i]=='o'|| word[i]=='u')&& vowel_passed==false) 
     {
        modified[0]=word[i];
	index++; 
	vowel_passed=true;
     }
     else{
       if (vowel_passed==false){
         substr[index1]=word[i];
	 index1++;
       }
       else{
	 modified[index]=word[i];
	 index++;
       }
     }
  }
  if (capitalized==true){
      modified[0]=toupper(modified[0]); 
  }
  substr[index1]='\0'; 
  modified[index]='\0'; 
  printf("%s", strcat(strcat(modified, substr),"ay"));
  translated=true;
}


int main(int argc, char *argv[]){
 if (argc>1){
   if (strcmp(argv[1], "-h") || strcmp(argv[1], "-?")){
      printf("%s\n", "This program implements the Pig Latin cypher!!! "); 
      return 1; 
   }
 }
 char c;
 char given[100];
 int k=0;

 // Input the string to be translated 
 while ((c=getchar())!='\n'){
   given[k]=c;
   k++; 
 }
 given[k]='\0'; 
 

 // RULE 1: First character is a vowel
 if (given[0]=='a' || given[0] =='e' || given[0] == 'i' || given[0]=='o' || given[0]=='u'){    
   printf("%s\n", strcat(given, "yay")); 
 }
 else{
 // RULE 2: Switch the order of the word after identifying a vowel
 // Punctuation: if there is a comma/period/q mark at the end of the word, it has to be saved and added to the end after 'ay'
 // Capitalization: check if a word starts with a capital letter and capitalize the first character of the resulting word
 char temp[100];
 int index=0;

 for (int j=0; j<(int) strlen(given); j++){
   if(isalpha(given[j])){
        translated=false; 
        temp[index]=given[j]; 
        index++;  
   }
   else {
	// Translate a word through function, print the characters that are not words
       temp[index]='\0';
       if (translated==false){ 
          translate(temp); 
          for (int i=0;i<(int) strlen(temp); i++){
	     temp[i]='\0'; 
	  }
       }	
       printf("%c", given[j]); 
       index=0;  
   }
   }
   if (translated==false){
     translate(temp);
   }
 }
 printf("\n");
 return 0;
}


 

