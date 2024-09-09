#define RDAPI_CONNECT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct MemoryStruct
{
  char *memory;
  size_t size;
} memstruct_t;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
memstruct_t send_request();
void clean_memory_struct(memstruct_t *memstruct);
