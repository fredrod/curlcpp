/*
 * File:    curl_init.h
 * Created by Frederik Rodrigue on 2015-06-15.
 */

#include <curl_init.h>
#include "curl_exception.h"

namespace curl {

// Implementation of the curl_environment getter
curl::curl_init &curl::curl_init::curl_environment() {
  static curl_init curl_environment;
  return curl_environment;
}

// Implementation of init
void curl_init::init() {
  curl_init &curl_environment = curl_init::curl_environment();
  if (curl_environment.flag != CURL_GLOBAL_ALL) {
    curl_environment.reset();
  }
}

// Implementation of init
void curl_init::init(const long flag) {
  curl_init &curl_environment = curl_init::curl_environment();
  if (curl_environment.flag != flag) {
    curl_environment.reset(flag);
  }
}

// Implementation of curl_init default Constructor
curl_init::curl_init() {
  flag = CURL_GLOBAL_ALL;
  cout << "curl_global_init" << endl;
  const CURLcode code = curl_global_init(flag);
  if (code != CURLE_OK) {
    throw curl_easy_exception(code, __FUNCTION__);
  }
}

// Implementation of curl_init Constructor
curl_init::curl_init(const long flag) {
  this->flag = flag;
  cout << "curl_global_init" << endl;
  const CURLcode code = curl_global_init(flag);
  if (code != CURLE_OK) {
    throw curl_easy_exception(code, __FUNCTION__);
  }
}

// Implementation of curl_init Destructor
curl_init::~curl_init() {
  cout << "curl_global_cleanup" << endl;
  curl_global_cleanup();
}

void curl_init::reset() {
  cout << "curl_global_cleanup" << endl;
  curl_global_cleanup();

  flag = CURL_GLOBAL_ALL;
  cout << "curl_global_init" << endl;
  const CURLcode code = curl_global_init(flag);
  if (code != CURLE_OK) {
    throw curl_easy_exception(code, __FUNCTION__);
  }
}

void curl_init::reset(const long flag) {
  cout << "curl_global_cleanup" << endl;
  curl_global_cleanup();

  this->flag = flag;
  cout << "curl_global_init" << endl;
  const CURLcode code = curl_global_init(flag);
  if (code != CURLE_OK) {
    throw curl_easy_exception(code, __FUNCTION__);
  }
}
}