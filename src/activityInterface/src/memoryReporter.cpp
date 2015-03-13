/*
 * Copyright (C) 2011 Department of Robotics Brain and Cognitive Sciences - Istituto Italiano di Tecnologia
 * Author: Vadim Tikhanoff
 * email:  vadim.tikhanoff@iit.it
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * A copy of the license can be found at
 * http://www.robotcub.org/icub/license/gpl.txt
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
 */

#include <yarp/os/Time.h>

#include "activityInterface.h"

using namespace yarp::os;

/**********************************************************/
MemoryReporter::MemoryReporter()
{
    manager=NULL;
}

/**********************************************************/
void MemoryReporter::setManager(ActivityInterface *manager)
{
    this->manager=manager;
}

/**********************************************************/
void MemoryReporter::report(const PortInfo &info)
{
    if ((manager!=NULL) && info.created && !info.incoming)
        manager->scheduleLoadMemory=true;
}

/**********************************************************/
PradaStatus::PradaStatus()
{
    manager=NULL;
    useCallback();
}

/**********************************************************/
void PradaStatus::setManager(ActivityInterface *manager)
{
    this->manager=manager;
}

/**********************************************************/
void PradaStatus::onRead(Bottle &status)
{
    if (status.size()>1)
        manager->processPradaStatus(status);
}
//empty line to make gcc happy