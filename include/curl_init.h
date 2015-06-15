/*
 * File:    curl_init.h
 * Created by Frederik Rodrigue on 2015-06-15.
 */

#ifndef __curlcpp__curl_init__
#define __curlcpp__curl_init__

namespace curl {
/**
 * This class is used to initialize and cleanup libcurl environment.
 */
class curl_init {
 public:

  /**
   * Initialize the curl environment with the default flag.
   */
  static void init();

  /**
   * Initialize the curl environment with user specified flag.
   */
  static void init(const long);

 private:

  /**
   * Method to get the current curl_environment.
   */
  static curl_init &curl_environment();

  /**
   * Contructor of the curl_init, it create the curl environment.
   */
  curl_init();

  /**
   * Contructor of the curl_init, it create the curl environment with the specified flag.
   */
  curl_init(const long);

  /**
   * Destructor of the curl_init, it cleanup the curl environment.
   */
  ~curl_init();

  /**
   * Clean and reinitialize the curl environment with the default flag.
   */
  void reset();

  /**
   * Clean and reinitialize the curl environment with the specified flag.
   */
  void reset(const long);

  long flag;

};

}


#endif /* defined(__curlcpp__curl_init__) */
