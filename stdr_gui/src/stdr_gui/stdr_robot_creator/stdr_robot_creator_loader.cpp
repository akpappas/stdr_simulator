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

#include "stdr_gui/stdr_robot_creator/stdr_robot_creator_loader.h"

namespace stdr_gui
{
  /**
  @brief Default contructor
  @param argc [int] Number of input arguments
  @param argv [char**] Input arguments
  @return void
  **/
  CRobotCreatorLoader::CRobotCreatorLoader(int argc, char **argv):
    robotPropLoader(argc,argv),
    laserPropLoader(argc,argv),
    sonarPropLoader(argc,argv),
    kinematicPropLoader(argc,argv),
    rfidAntennaPropLoader(argc,argv),
    argc_(argc),
    argv_(argv)
  {
    setupUi(this);
    
    setupInitialTree();
    robotPreviewLabel->setScaledContents(true);
    
    robotPreviewImage = QImage(500,500,QImage::Format_RGB32);
    robotPreviewImage.fill(QColor(220,220,220,1));
  }
  
  /**
  @brief Sets up the information tree in robot creator widget
  @return void
  **/
  void CRobotCreatorLoader::setupInitialTree(void)
  {
    addIcon.addFile(QString::fromUtf8((
      stdr_gui_tools::getRosPackagePath("stdr_gui") + 
      std::string("/resources/images/add_icon.png")).c_str()), 
      QSize(16,16), 
      QIcon::Normal, 
      QIcon::Off);
    editIcon.addFile(QString::fromUtf8((
      stdr_gui_tools::getRosPackagePath("stdr_gui") + 
      std::string("/resources/images/edit_icon.png")).c_str()), 
      QSize(16,16), 
      QIcon::Normal, 
      QIcon::Off);
    removeIcon.addFile(QString::fromUtf8((
      stdr_gui_tools::getRosPackagePath("stdr_gui") + 
      std::string("/resources/images/remove_icon.png")).c_str()), 
      QSize(16,16), 
      QIcon::Normal, 
      QIcon::Off);
    saveIcon.addFile(QString::fromUtf8((
      stdr_gui_tools::getRosPackagePath("stdr_gui") + 
      std::string("/resources/images/save_icon.png")).c_str()), 
      QSize(16,16), 
      QIcon::Normal, 
      QIcon::Off);
    loadIcon.addFile(QString::fromUtf8((
      stdr_gui_tools::getRosPackagePath("stdr_gui") + 
      std::string("/resources/images/load_icon.png")).c_str()), 
      QSize(16,16), 
      QIcon::Normal, 
      QIcon::Off);
    
    robotTreeWidget->setColumnWidth(0,150);
    robotTreeWidget->setColumnWidth(1,60);
    robotTreeWidget->setColumnWidth(2,20);
    robotTreeWidget->setColumnWidth(3,20);
    robotTreeWidget->setColumnWidth(4,20);

    QStringList ColumnNames;
    ColumnNames << "Robot parts" << "Info" << "" << "" << "";
 
    robotTreeWidget->setHeaderLabels(ColumnNames);
    
    robotNode.setText(0,"Robot");
    lasersNode.setText(0,"Lasers");
    sonarsNode.setText(0,"Sonars");
    //~ rfidAntennasNode.setText(0,"Rfid Antennas");
    //~ kinematicNode.setText(0,"Kinematic");
    
    robotNode.setIcon(2,editIcon);
    robotNode.setIcon(3,saveIcon);
    robotNode.setIcon(4,loadIcon);
    lasersNode.setIcon(2,addIcon);
    sonarsNode.setIcon(2,addIcon);
    //~ rfidAntennasNode.setIcon(2,addIcon);
    //~ kinematicNode.setIcon(2,editIcon);
    
    robotTreeWidget->addTopLevelItem(&robotNode);
    robotTreeWidget->addTopLevelItem(&lasersNode);
    robotTreeWidget->addTopLevelItem(&sonarsNode);
    //~ robotTreeWidget->addTopLevelItem(&rfidAntennasNode);
    //~ robotTreeWidget->addTopLevelItem(&kinematicNode);
    
    robotInfoShape.setText(0,"Shape");
    robotInfoShape.setText(1,"Circle");
    robotInfoOrientation.setText(0,"Orientation");
    robotInfoOrientation.setText(1,"0");

    
    robotNode.addChild(&robotInfoShape);
    robotNode.addChild(&robotInfoRadius);
    robotNode.addChild(&robotInfoOrientation);
    
    robotNode.setExpanded(true);
    lasersNode.setExpanded(true);
    sonarsNode.setExpanded(true);
    //~ rfidAntennasNode.setExpanded(true);
    //~ kinematicNode.setExpanded(true);
    
    robotTreeWidget->resizeColumnToContents(0);
    robotTreeWidget->resizeColumnToContents(1);
    robotTreeWidget->resizeColumnToContents(2);
    robotTreeWidget->resizeColumnToContents(3);
    robotTreeWidget->resizeColumnToContents(4);
  }
}
