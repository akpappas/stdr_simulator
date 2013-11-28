/******************************************************************************
   STDR Simulator - Simple Two DImensional Robot Simulator
   Copyright (C) 2013 STDR Simulator
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
   
   Authors : 
   * Manos Tsardoulias, etsardou@gmail.com
   * Aris Thallas, aris.thallas@gmail.com
   * Chris Zalidis, zalidis@gmail.com 
******************************************************************************/

#ifndef STDR_GUI_ROBOT_CONTAINER
#define STDR_GUI_ROBOT_CONTAINER

#include "stdr_gui/stdr_tools.h"
#include "stdr_gui/stdr_gui_sensors/stdr_gui_laser.h"
#include "stdr_gui/stdr_gui_sensors/stdr_gui_rfid.h"
#include "stdr_gui/stdr_gui_sensors/stdr_gui_sonar.h"

namespace stdr_gui{
	
	class GuiRobot{
			std::vector<GuiLaser> _lasers;
			std::vector<GuiSonar> _sonars;
			std::vector<GuiRfid> _rfids;
			
			std::string frameId_;
			
			geometry_msgs::Pose2D initialPose;
			geometry_msgs::Pose2D currentPose;
			float resolution;
			stdr_msgs::FootprintMsg footprint;
			float radius;
			void drawSelf(QImage *m);
			tf::TransformListener listener;
			bool showLabel;
			bool showCircles;
		public:
			GuiRobot(void);
			GuiRobot(const GuiRobot& other);
			GuiRobot(const stdr_msgs::RobotIndexedMsg& msg);
			~GuiRobot(void);
			std::string getFrameId(void);
			void draw(QImage *m,float ocgd);
			void drawLabel(QImage *m,float ocgd);
			bool checkEventProximity(QPoint p);
			void setShowLabel(bool b);
			void toggleShowLabel(void);
			bool getShowLabel(void);
			void toggleShowCircles(void);
	};	
}

#endif