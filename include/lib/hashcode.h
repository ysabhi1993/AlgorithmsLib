#ifndef HASHCODE_H
#define HASHCODE_H

#include <string>
#include <utility>

/**
 * Hashcode overloads for all primitive types  
 */
int hashcode(bool key);
int hashcode(char key);
int hashcode(int key);
int hashcode(unsigned int key);
int hashcode(float key);
int hashcode(double key);
int hashcode(long key);
int hashcode(unsigned long key);
int hashcode(long double key);
int hashcode(short key);
int hashcode(unsigned short key);
int hashcode(const char* key);
int hashcode(const std::string& key);
int hashcode(void *key);

/**
 * Functions returning constants 
 */
int hashSeed();
int hashMultiplier();
int hashMask();

template <typename T1, typename T2, typename... Others>
int hashcode(T1&& first, T2&& second, Others&&... remaining) {
  int result = hashSeed();
  
  /*Compute hashcode for last n - 1 elements*/
  result += hashcode(std::forward<T2>(second), std::forward<Others>(remaining)...);

  /*Update hash and add in first element*/
  result *= hashMultiplier();
  result += hashcode(std::forward<T1>(first));

  return hashcode(result);
}

#endif //HASHCODE_H