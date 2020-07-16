#include "zlib.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  const unsigned char pData[] = "testing";
  unsigned long nDataSize = 100;

  printf("Initial size: %d\n", nDataSize);

  unsigned long nCompressedDataSize = nDataSize;
  unsigned char * pCompressedData = new unsigned char[nCompressedDataSize];
  
  int nResult = compress2(pCompressedData, &nCompressedDataSize, pData, nDataSize, 9);

  if (nResult == Z_OK)
  {
    printf("Compressed data[%d]: %x\n", nCompressedDataSize, pCompressedData);
    for (int i = 0; i < nCompressedDataSize; ++i)
    {
      if (i%16==0) printf("\n");
      printf("0x%-02X ", pCompressedData[i]);
    }
    printf("\n");

    unsigned char * pUncompressedData = new unsigned char[nDataSize];
    nResult = uncompress(pUncompressedData, &nDataSize, pCompressedData, nCompressedDataSize);
    if (nResult == Z_OK)
    {
      printf("Uncompressed size: %d\n", nDataSize);
      if (memcmp(pUncompressedData, pData, nDataSize) == 0){
        printf("Great Success: %s\n", pUncompressedData);
      }else{
        printf("Fail: %s", pUncompressedData);
      }
    }
    delete [] pUncompressedData;
  }

  delete [] pCompressedData;

  return 0;
}

int demo(int argc, char *argv[])
{
    unsigned long a;
    unsigned char buffer[1024];
    a = 1024;
    compress(buffer, &a,(unsigned char *)"testing",7);
    printf("gzip testing: %x", buffer);
    return 0;
}