#include "./rdapi_connect.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>


size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t real_size = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  char *ptr = realloc(mem->memory, mem->size + real_size + 1);
  if (ptr == NULL)
  {
    printf("Not enought memory (realloc returned NULL)\n");
    return 0;
  }

  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, real_size);
  mem->size += real_size;
  mem->memory[mem->size] = 0;

  return real_size;
} 



memstruct_t send_request()
{
  CURL *curl;
  CURLcode res;

  struct MemoryStruct chunk;
  chunk.memory = malloc(1);
  chunk.size = 0;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();

  if (curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/todos/1");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK) { fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));}
        
    curl_easy_cleanup(curl);
  }
  return chunk;
}

void clean_memory_struct(memstruct_t *memstruct)
{
  if (memstruct->memory)
    free(memstruct->memory);
  curl_global_cleanup();
}
/*
int main(void)
{
  memstruct_t chunk;
  chunk = send_request();
  printf("%s\n", chunk.memory);
  clean_memory_struct(&chunk);
  return 0;
}
*/
