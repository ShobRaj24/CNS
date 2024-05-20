#include<stdio.h> 
void caesar(char text[], int shift){ 
for(int i=0;text[i]!='\0';++i){ 

 
if(text[i]>='a'&&text[i]<='z') 
text[i]='a'+(text[i]- 'a'+shift)%26; 
else if(text[i]>='A'&&text[i]<='Z') 
text[i]='A'+(text[i]- 'A'+shift)%26; 
} 
} 
 
int main(){ 
char message[]="hellohowareu"; 
int key=3; 
 
printf("Originalmessage:%s\n",message); 
 
//Encryption 
caesar(message,key); 
printf("Encryptedmessage:%s\n",message); 
 
//Decryption 
caesar(message,-key); 
printf("Decryptedmessage:%s\n",message); 
 
return 0; 
} 