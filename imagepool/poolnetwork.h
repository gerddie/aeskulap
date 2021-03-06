/*
    Aeskulap ImagePool - DICOM abstraction library
    Copyright (C) 2005  Alexander Pipelka

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

    Alexander Pipelka
*/

#ifndef IMAGEPOOL_NETWORK_H
#define IMAGEPOOL_NETWORK_H

#include "poolassociation.h"

class Network {
public:

	/**
	constructors
	*/
	Network();
	virtual ~Network();

	/**
	Initialize the dicom network
	*/
	OFCondition InitializeNetwork(int timeout=20, int port = 0);

	/**
	Drop the dicom network
	*/
	OFCondition DropNetwork();

	/**
	Connect an association to the specified host
	*/
	OFCondition ConnectAssociation(Association* assoc, int lossy = 0);

	/**
	Send C-Echo request to dicom node
	*/
	bool SendEchoRequest(const std::string& title, const std::string& peer, int port, const std::string& ouraet);

	/**
	Get the pointer to the internal dcmtk network variable (sorry)
	*/
	T_ASC_Network* GetDcmtkNet();

	void SetDcmtkNet(T_ASC_Network* n);
	
	/**
	static const char* GetCurrDate();
	*/

	/**
	static const char* GetCurrTime();
	*/

private:

	/**
	Add all possible presentation contexts to association parameters
	*/
	static OFCondition addAllStoragePresentationContexts(T_ASC_Parameters *params, bool bProposeCompression = true, int lossy = 0);

	/**
	Connect to a host and try to establish an association
	*/
	OFCondition ASC_ConnectAssociation(Association* assoc, const std::string& peerTitle, const std::string& peer, int port, const std::string& ouraet, const char *abstractSyntax = NULL, int lossy = 0);

	/**
	THE dicom network
	*/
	static T_ASC_Network* net;

	friend class Association;
};

#endif // IMAGEPOOL_NETWORK_H
