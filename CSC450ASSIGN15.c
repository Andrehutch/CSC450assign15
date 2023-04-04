#include <studio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    const char * filePath = "gensis.txt";
    const char * copyPath = "gensis_copy.txt";
    FILE * inputStream = fopen(filePath, "rb");
    FILE * ouputStream = fopen(copyPath, "wb");

    int f_size = 0;
    fseek(inputStream, 0, SEEK_END);
    f_size = ftell(inputStream);
    int end = 0;
    end = f_size / 2;
    int p_id = fork();

    if (p_id == 0){
        fseek(inputStream, 0, SEEK_SET);
        char buffer[end];
        fread(buffer, end, 1, inputStream)
        fwrite(buffer, end, 1, outputStream);
        fflush(outputStream);
        fclose(inputStream);
        fclose(outputStream);
    }else {
        fseek(inputStream, end + 1, SEEK_SET);
        char buffer[f_size - end];
        fread(buffer, (f_size-end), 1, inputStream)
        fseek(outputStream, end + 1, SEEK_SET);
        sleep(1);
        fwrite(buffer, (f_size-end), 1, outputStream);
        fflush(outputStream);
        fclose(inputStream);
        fclose(outputStream);
    }

    return 0;
}