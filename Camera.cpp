/************************************************************/
/*    NAME: David Battle                                    */
/*    ORGN: MISSION SYSTEMS PTY LTD                         */
/*    FILE: Camera.cpp                                      */
/*    DATE: 9 Jan 2019                                      */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "Camera.h"
#include <nlohmann/json.hpp>

using namespace std;
using namespace cv;
using json = nlohmann::json;

//---------------------------------------------------------
// Constructor

Camera::Camera()
{
}

//---------------------------------------------------------
// Destructor

Camera::~Camera()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool Camera::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
   
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key  = msg.GetKey();
    double dval = msg.GetDouble();
    string sval = msg.GetString();

    // Process camera message
    if (key == "CAMERA_DATA") {

      size_t numBytes = msg.GetBinaryDataSize();

      // Pointer to image data
      void *ptr = msg.GetBinaryData();

      // // Read RGBA image
      Mat raw = Mat(600, 800, CV_8UC4, ptr);

      // Convert to BGRA
      cvtColor(raw, m_image, COLOR_RGBA2BGRA);

      // Read BGR image
      // Mat raw = Mat(720, 1280, CV_8UC3, ptr);
      // Mat raw = Mat(480, 640, CV_8UC3, ptr);
      // Mat raw = Mat(240, 424, CV_8UC3, ptr);

      // Convert to BGRA
      // cvtColor(raw, m_image, COLOR_BGR2BGRA);

      // Read Z16 image
      // Mat raw = Mat(720, 1280, CV_16UC1, ptr);

      // // Convert to BGRA
      // cvtColor(raw, m_image, COLOR_GRAY2BGR);
    } 
  }
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool Camera::OnConnectToServer()
{
   // register for variables here
   // possibly look at the mission file?
   // m_MissionReader.GetConfigurationParam("Name", <string>);
   // m_Comms.Register("VARNAME", 0);
	
   RegisterVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool Camera::Iterate()
{

  if ( m_image.data )
  {
    imshow("Colour Landing Camera", m_image);
    waitKey(1);
  }

  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool Camera::OnStartUp()
{
  list<string> sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(m_MissionReader.GetConfiguration(GetAppName(), sParams)) {
    list<string>::iterator p;
    for(p=sParams.begin(); p!=sParams.end(); p++) {
      string original_line = *p;
      string param = stripBlankEnds(toupper(biteString(*p, '=')));
      string value = stripBlankEnds(*p);
      
      if(param == "FOO") {
        //handled
      }
      else if(param == "BAR") {
        //handled
      }
    }
  }
  
  RegisterVariables();	

  namedWindow("Colour Landing Camera", WINDOW_AUTOSIZE );

  return(true);
}

//---------------------------------------------------------
// Procedure: RegisterVariables

void Camera::RegisterVariables()
{  
  Register("CAMERA_DATA", 0);
}

