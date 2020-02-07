/************************************************************/
/*    NAME:                                               */
/*    ORGN: MIT                                             */
/*    FILE: Camera.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef Camera_HEADER
#define Camera_HEADER

#include "MOOS/libMOOS/MOOSLib.h"
#include "MOOS/libMOOSGeodesy/MOOSGeodesy.h"
#include <opencv2/opencv.hpp>

class Camera : public CMOOSApp
{
 public:
   Camera();
   ~Camera();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected:
   void RegisterVariables();

   cv::Mat m_image;
   std::string msg_name;

 private: // Configuration variables

 private: // State variables
};

#endif 
