<?xml version="1.0"?>
<?CDF VERSION="6.0"?>
<INSTALLATION>
<SOFTPKG NAME="{076E75BF-A643-415F-9E91-22EB4742763B}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>Remote Panel Server for LabVIEW RT</TITLE>
	<ABSTRACT>Allows accessing VIs as remote panels.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/webserver/LVModules/liblvauthmodule.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/webserver/LVModules/liblvrfpmodule.so.18.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/labview/webserver/LVModules/liblvauthmodule.so"/>
		<SYMLINK LINK="/usr/local/natinst/labview/webserver/LVModules/lvauthmodule.so"/>
		<SYMLINK LINK="/usr/local/natinst/labview/webserver/LVModules/liblvrfpmodule.so"/>
		<SYMLINK LINK="/usr/local/natinst/labview/webserver/LVModules/lvrfpmodule.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="12.0.0">
				<TITLE>LabVIEW RT</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{6B8CDAFE-4D77-4DF8-BB8F-EF0B0CF70EDE}" VERSION="14.0.0">
				<TITLE>Appweb</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{18108842-F963-4FE1-B709-1C79F745FF71}" VERSION="18.0.0" TYPE="VISIBLE" HIDEVERSION="YES">
	<TITLE>NI-VISA ENET Passport</TITLE>
	<ABSTRACT>The NI-VISA Ethernet Passport provides support for VISA applications and drivers that use TCP/IP resources. This includes VXI-11 and HiSLIP devices as well as raw sockets.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="ni-visa-passport-enet_armv7a.tar" TYPE="TAR"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{2C9F0C7B-DB26-40B1-A078-ABFB614C013E}" VERSION="18.0.0">
				<TITLE>NI-VISA</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="12.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{37638B3C-551E-46D4-9503-2DBBB5B1132D}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>Hardware Configuration Web Support</TITLE>
	<ABSTRACT>Hardware Configuration Web Support installs the NI Web-based Configuration and Monitoring System Configuration page. Use this page to view and set system and startup settings for your target.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/ExtensionMetaData.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/HardwareConfig.xap"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/DisplayInfo.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/DisplayInfo.de.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/DisplayInfo.fr.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/DisplayInfo.ja.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/DisplayInfo.ko.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/DisplayInfo.zh-Hans.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/Help/en/HardwareConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/Help/de/HardwareConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/Help/fr/HardwareConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/Help/ja/HardwareConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/Help/ko/HardwareConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/Help/zh-Hans/HardwareConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/HardwareConfig/Images/HardwareConfig.png"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{25D93C94-D8AB-4DEE-930D-7CC4B0EBB92B}" VERSION="14.0.0">
				<TITLE>NI Web-based Configuration and Monitoring</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{75BE83A6-6097-4DD3-8E3E-5D6384A1D095}" VERSION="18.0.0">
				<TITLE>WIF core dependencies</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{7E56CD7B-42D6-46E0-8638-DE2D819A3A9D}" VERSION="18.0.0">
				<TITLE>NI System API Silverlight client</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{8946D3FB-8D14-4BFC-B401-2827F86364EB}" VERSION="18.0.0">
				<TITLE>NI System Configuration Remote Support</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{3B87558E-D9A4-49CC-9377-BEB8659CFD50}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>NI Vision RT</TITLE>
	<ABSTRACT>NI Vision provides support for image processing and machine vision functions.</ABSTRACT>
	<IMPLEMENTATION>
		<EXCEPTPROCESSOR VALUE="774C"/>
		<EXCEPTPROCESSOR VALUE="774E"/>
		<OS VALUE="Linux-ARMv7-A"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{CAFF132A-40E3-4D34-9C2B-1664CB9E6AD5}" VERSION="18.0.0">
				<TITLE>NIVISSVC</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="15.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{551562B3-1C09-4A9D-A96F-4F769236A5D4}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>IP Camera Support</TITLE>
	<ABSTRACT>IP Camera Support installs support for using the NI-IMAQdx driver to access IP cameras.</ABSTRACT>
	<IMPLEMENTATION>
		<EXCEPTPROCESSOR VALUE="774C"/>
		<EXCEPTPROCESSOR VALUE="774E"/>
		<OS VALUE="Linux-ARMv7-A"/>
		<OS VALUE="NI-Linux x64"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{6088DBFB-9F25-41D3-A72C-D7849AE12A41}" VERSION="18.0.0">
				<TITLE>NI-IMAQdx</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{AAD95C0A-FD47-4CDD-821D-C4B4EF76DDDA}" VERSION="1.2.0">
				<TITLE>mDNSResponder</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<MERGEINI TARGET="/etc/natinst/share/ni-rt.ini">[IMAQDX]
IPCameraSupportEnabled=true

		</MERGEINI>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{5A0FD458-F336-4749-8548-9326219BB596}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>Software Management Web Support</TITLE>
	<ABSTRACT>Software Management Web Support installs the NI Web-based Configuration and Monitoring Software Management page. Use this page to view information about the software installed on your target.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/ExtensionMetaData.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/SoftwareManagement.xap"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/DisplayInfo.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/DisplayInfo.de.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/DisplayInfo.fr.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/DisplayInfo.ja.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/DisplayInfo.ko.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/DisplayInfo.zh-Hans.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/Help/en/SoftwareManagementHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/Help/de/SoftwareManagementHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/Help/fr/SoftwareManagementHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/Help/ja/SoftwareManagementHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/Help/ko/SoftwareManagementHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/Help/zh-Hans/SoftwareManagementHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SoftwareManagement/Images/SoftwareManagementIcon.png"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{25D93C94-D8AB-4DEE-930D-7CC4B0EBB92B}" VERSION="14.0.0">
				<TITLE>NI Web-based Configuration and Monitoring</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{75BE83A6-6097-4DD3-8E3E-5D6384A1D095}" VERSION="18.0.0">
				<TITLE>WIF core dependencies</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{7E56CD7B-42D6-46E0-8638-DE2D819A3A9D}" VERSION="18.0.0">
				<TITLE>NI System API Silverlight client</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{753C981D-320F-4A3A-8443-436DF4FEEA3B}" VERSION="19.0.0" TYPE="VISIBLE">
	<TITLE>_FRC_</TITLE>
	<IMPLEMENTATION>
		<PROCESSOR VALUE="76F2"/>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="frc.tar" TYPE="TAR"/>
		<SYMLINK LINK="/usr/local/frc/lib/libRoboRIO_FRC_ChipObject.so"/>
		<SYMLINK LINK="/usr/local/frc/lib/libFRC_NetworkCommunication.so"/>
		<SYMLINK LINK="/usr/local/frc/lib/libFRC_NetworkCommunicationLV.so"/>
		<SYMLINK LINK="/usr/local/frc/lib/libi2c.so"/>
		<SYMLINK LINK="/usr/local/frc/lib/libspi.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libusb.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libmyrio_hid.so"/>
		<SYMLINK LINK="/etc/init.d/FRCNetComm"/>
		<SYMLINK LINK="/home/lvuser/FRC_UserProgram.log"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{BE793622-69E8-4F0F-B3AB-DB06517FF276}" VERSION="">
				<TITLE>CompactRIO Support</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<MERGEINI TARGET="/etc/natinst/share/lvrt.conf">[LVRT]
RTSupportsAppEvents=TRUE
SocketSetReuseAddr=TRUE

		</MERGEINI>
		<MERGEINI TARGET="/etc/natinst/share/ni-rt.ini">[STARTUP]
YouOnlyLiveTwice=FALSE

		</MERGEINI>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{78036FC0-F244-4AB4-9816-0A5415E3F22C}" VERSION="18.0.0" TYPE="VISIBLE" HIDEVERSION="YES">
	<TITLE>NI-VISA ENET-ASRL Passport</TITLE>
	<ABSTRACT>The NI-VISA ENET-Serial Passport provides support for VISA applications and drivers that use ENET-Serial resources. This includes both RS-232 and RS-485.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="ni-visa-passport-enet-serial_armv7a.tar" TYPE="TAR"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{2C9F0C7B-DB26-40B1-A078-ABFB614C013E}" VERSION="18.0.0">
				<TITLE>NI-VISA</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="12.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{78635DF3-9C05-418F-BCAC-AD08D85C172E}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>USB3 Vision Support</TITLE>
	<ABSTRACT>USB3 Vision Support installs support for using the NI-IMAQdx driver to access USB3 Vision cameras.</ABSTRACT>
	<IMPLEMENTATION>
		<EXCEPTPROCESSOR VALUE="774C"/>
		<EXCEPTPROCESSOR VALUE="774E"/>
		<OS VALUE="Linux-ARMv7-A"/>
		<OS VALUE="NI-Linux x64"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{6088DBFB-9F25-41D3-A72C-D7849AE12A41}" VERSION="18.0.0">
				<TITLE>NI-IMAQdx</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{FA4C4A5D-A559-4916-AB5D-ED272FA607E4}" VERSION="3.0.2">
				<TITLE>GenICam RT</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{301C450E-970E-4FFB-9ADF-F89EBF5AAEAF}" VERSION="18.0.0">
				<TITLE>NI-U3V RT</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{07B9A600-7256-4FF5-B502-DE5FDD099A34}" VERSION="18.0.0">
				<TITLE>NI-U3V RT Target Options</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<MERGEINI TARGET="/etc/natinst/share/ni-rt.ini">[IMAQDX]
U3VCameraSupportEnabled=true

		</MERGEINI>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{07B9A600-7256-4FF5-B502-DE5FDD099A34}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI-U3V RT Target Options</TITLE>
	<ABSTRACT>Additional target-specific options for USB3 Vision support</ABSTRACT>
	<IMPLEMENTATION>
		<PROCESSOR VALUE="76F2"/>
		<MERGEINI TARGET="/etc/natinst/share/ni-rt.ini">[IMAQDX]
U3V_MaximumCurrentUSB20_mA=900
U3V_MaxBandwidthUSB20_BytesPerSecond=33000000

		</MERGEINI>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{301C450E-970E-4FFB-9ADF-F89EBF5AAEAF}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI-U3V RT</TITLE>
	<ABSTRACT>The core components required to use USB3 Vision cameras.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libniu3v.so.18.0.0"/>
		<CODEBASE FILENAME="u3v.tar" TYPE="TAR"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libniu3v.so.18"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libniu3v.so"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{8D1E7E99-60D5-44F0-A5AD-65908580B9C6}" VERSION="1.4.0" TYPE="VISIBLE">
	<TITLE>Legacy FTP Server (deprecated)</TITLE>
	<ABSTRACT>Legacy FTP file transfer support. Note: National Instruments recommends using WebDAV as the file transfer mechanism for improved security. For information about using WebDAV, visit ni.com/info and enter the Info Code: RTFileTransfer</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="vsftpd_installer_4.0.0.tar" TYPE="TAR"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="18.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{9992C06F-FBAC-47DE-912F-3F4A1CF6A284}" VERSION="18.0.0" TYPE="VISIBLE" HIDEVERSION="YES">
	<TITLE>NI-VISA USB Passport</TITLE>
	<ABSTRACT>The NI-VISA USB Passport provides support for VISA applications and drivers that use USB resources. This includes USB-TMC devices as well as raw data transfer.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="ni-visa-passport-usb_armv7a.tar" TYPE="TAR"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{2C9F0C7B-DB26-40B1-A078-ABFB614C013E}" VERSION="18.0.0">
				<TITLE>NI-VISA</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="12.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{A7E4BD0D-3E71-4ECD-B9FC-1D360BED0769}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>Time Configuration Web Support</TITLE>
	<ABSTRACT>Time Configuration Web Support installs the NI Web-based Configuration and Monitoring Time Configuration page. Use this page to configure the date and time settings for your target.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/ExtensionMetaData.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/TimeConfig.xap"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/DisplayInfo.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/DisplayInfo.de.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/DisplayInfo.fr.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/DisplayInfo.ja.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/DisplayInfo.ko.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/DisplayInfo.zh-Hans.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/Help/en/TimeConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/Help/de/TimeConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/Help/fr/TimeConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/Help/ja/TimeConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/Help/ko/TimeConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/Help/zh-Hans/TimeConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/TimeConfig/Images/TimeConfigIcon.png"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{25D93C94-D8AB-4DEE-930D-7CC4B0EBB92B}" VERSION="14.0.0">
				<TITLE>NI Web-based Configuration and Monitoring</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{75BE83A6-6097-4DD3-8E3E-5D6384A1D095}" VERSION="18.0.0">
				<TITLE>WIF core dependencies</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{7E56CD7B-42D6-46E0-8638-DE2D819A3A9D}" VERSION="18.0.0">
				<TITLE>NI System API Silverlight client</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{AAD95C0A-FD47-4CDD-821D-C4B4EF76DDDA}" VERSION="14.0.5" TYPE="HIDDEN">
	<TITLE>mDNSResponder</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="nimdnsResponder.tar" TYPE="TAR"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libnimdnsResponder.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libnss_nimdns.so"/>
		<SYMLINK LINK="/etc/init.d/nimdnsResponder"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{ACC5589E-C881-40D8-868A-E1BD968C9304}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>HTTP Client with SSL Support</TITLE>
	<ABSTRACT>This is used by the LabVIEW HTTP Client palette and includes support for HTTPS connections.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/libni_httpClient.so.16.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/labview/libni_httpClient.so"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="18.0.0">
				<TITLE>LabVIEW RT</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{C12BE192-909C-4C10-8D6D-3FA49C4D7DB2}" VERSION="16.0.0">
				<TITLE>NI cURL</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{B0E93840-A444-4B82-96C6-5167C91C470F}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>NI-Embedded CAN for RIO</TITLE>
	<ABSTRACT>NI-Embedded CAN for RIO provides support for the embedded CAN ports on RIO to transmit and receive CAN frames.</ABSTRACT>
	<IMPLEMENTATION>
		<PROCESSOR VALUE="76F2"/>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="niembcanzynqk.tar" TYPE="TAR"/>
		<CODEBASE FILENAME="/usr/local/natinst/nibds/clients/niembcanzynqk"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libnirio_emb_can.so.16.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/librioembeddedcanlvapi.so.16.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/English/rioEmbeddedCAN.err"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libnirio_emb_can.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/librioembeddedcanlvapi.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="14.0.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{ED0E40C9-8523-463D-B9ED-125DC2D67A62}" VERSION="15.0.0">
				<TITLE>NI-KAL</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{39864828-E46E-461E-8780-9C50ADA29115}" VERSION="11.0.0">
				<TITLE>Base System</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<MERGEINI TARGET="/etc/natinst/share/ni-rt.ini">[EMBCAN]
TransceiverGPIOPort1=20

		</MERGEINI>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{B5A0EBCC-49EA-4B21-9B63-3E52754A3266}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>USB Webcam Support</TITLE>
	<ABSTRACT>USB Webcam Support installs support for using the NI-IMAQdx driver to access USB webcams supporting USB Video Class (UVC).</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<OS VALUE="NI-Linux x64"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{6088DBFB-9F25-41D3-A72C-D7849AE12A41}" VERSION="18.0.0">
				<TITLE>NI-IMAQdx</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="13.0.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<MERGEINI TARGET="/etc/natinst/share/ni-rt.ini">[IMAQDX]
UVCCameraSupportEnabled=true

[RTLINUXMEMRESERVE]
IMAQdxUVCCameraSupport=8

		</MERGEINI>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{6088DBFB-9F25-41D3-A72C-D7849AE12A41}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>NI-IMAQdx</TITLE>
	<ABSTRACT>NI-IMAQdx is driver software for NI 177x and ISC-178x smart cameras, as well as IEEE 1394, GigE Vision, USB3 Vision, and IP cameras.</ABSTRACT>
	<IMPLEMENTATION>
		<EXCEPTPROCESSOR VALUE="774C"/>
		<EXCEPTPROCESSOR VALUE="774E"/>
		<EXCEPTPROCESSOR VALUE="76CE"/>
		<EXCEPTPROCESSOR VALUE="77AA"/>
		<EXCEPTPROCESSOR VALUE="7880"/>
		<EXCEPTPROCESSOR VALUE="787F"/>
		<DEVICECLASS VALUE="CRIO"/>
		<DEVICECLASS VALUE="CDAQ"/>
		<DEVICECLASS VALUE="FLEXRIO"/>
		<DEVICECLASS VALUE="INDUSTRIALCONTROLLER"/>
		<DEVICECLASS VALUE="PXI"/>
		<OS VALUE="Linux-ARMv7-A"/>
		<OS VALUE="NI-Linux x64"/>
		<FEATURE SELECT="YES">
			<SOFTPKG NAME="{237176DF-4833-4903-A4DC-3036DB1955FB}" VERSION="18.0.0">
				<TITLE>GigE Vision Camera Support</TITLE>
			</SOFTPKG>
		</FEATURE>
		<FEATURE SELECT="YES">
			<SOFTPKG NAME="{78635DF3-9C05-418F-BCAC-AD08D85C172E}" VERSION="18.0.0">
				<TITLE>USB3 Vision Support</TITLE>
			</SOFTPKG>
		</FEATURE>
		<FEATURE SELECT="YES">
			<SOFTPKG NAME="{B5A0EBCC-49EA-4B21-9B63-3E52754A3266}" VERSION="18.0.0">
				<TITLE>USB Webcam Support</TITLE>
			</SOFTPKG>
		</FEATURE>
		<FEATURE SELECT="YES">
			<SOFTPKG NAME="{551562B3-1C09-4A9D-A96F-4F769236A5D4}" VERSION="18.0.0">
				<TITLE>IP Camera Support</TITLE>
			</SOFTPKG>
		</FEATURE>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{7E9B9F24-B855-41DD-9C76-17E7561E4BAB}" VERSION="18.0.0">
				<TITLE>NI-IMAQdx RT Common</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{7E9B9F24-B855-41DD-9C76-17E7561E4BAB}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI-IMAQdx RT Common</TITLE>
	<IMPLEMENTATION>
		<EXCEPTPROCESSOR VALUE="774C"/>
		<EXCEPTPROCESSOR VALUE="774E"/>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libniimaqdx.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/English/niimaqdx.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/French/niimaqdx.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/German/niimaqdx.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/Japanese/niimaqdx.err"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libniimaqdx.so.14"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libniimaqdx.so"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{FA4C4A5D-A559-4916-AB5D-ED272FA607E4}" VERSION="3.0.2">
				<TITLE>GenICam RT</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{742C82AD-223A-4CCE-AFEC-55D0C1A659E7}" VERSION="18.0.0">
				<TITLE>NI-APAL</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{CAFF132A-40E3-4D34-9C2B-1664CB9E6AD5}" VERSION="14.5.0">
				<TITLE>NIVISSVC</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{13C56201-055C-41CB-807E-27FCF5C35DB7}" VERSION="3.4.0">
				<TITLE>NI-IMAQ Server</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{84C09D5C-116F-40A1-81AE-7037903B98BD}" VERSION="15.0.0">
				<TITLE>NI-PAL</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{5AE03CDD-4EB2-45C2-9B9B-AF2D07C8DF86}" VERSION="1.0.0">
				<TITLE>NI-IMAQdx System API Expert</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<MERGEINI TARGET="/etc/natinst/share/ni-rt.ini">[IMAQDX]
InstalledVersion=18.0.0.3.0

		</MERGEINI>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{13C56201-055C-41CB-807E-27FCF5C35DB7}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI-IMAQ Server</TITLE>
	<ABSTRACT>The core components required for IMAQ Configuration.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<OS VALUE="NI-Linux x64"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{0BCF72D8-8515-4CB5-8140-F3074921BCD7}" VERSION="18.0.0">
				<TITLE>NI-IMAQ Server Common</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{0BCF72D8-8515-4CB5-8140-F3074921BCD7}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI-IMAQ Server Common</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libimaqcfgs.so.18.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libimaqcfgs.so.18"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libimaqcfgs.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="13.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{CAFF132A-40E3-4D34-9C2B-1664CB9E6AD5}" VERSION="12.1.0">
				<TITLE>NIVISSVC</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<MERGEINI TARGET="/etc/natinst/share/ni-rt.ini">[LVRT]
StartupDLLs=libimaqcfgs.so;

		</MERGEINI>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{5AE03CDD-4EB2-45C2-9B9B-AF2D07C8DF86}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI-IMAQdx System API Expert</TITLE>
	<ABSTRACT>Required components to get NI-IMAQdx camera properties through System Configuration Services</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libniimaqdxSysapiExpert.so.18.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libniimaqdxSysapiExpert.so.18"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libniimaqdxSysapiExpert.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{5FEB7A50-4EFF-416F-9EE9-EC94006BAA66}" VERSION="14.0.0">
				<TITLE>NI System API</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<MERGEINI TARGET="/usr/local/natinst/share/nisysapi.ini">[NIIMAQDX]
Path=/usr/local/natinst/lib/libniimaqdxSysapiExpert.so.18.0.0
ExpertFactory=createIMAQdxSysapiExpert

		</MERGEINI>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{84C09D5C-116F-40A1-81AE-7037903B98BD}" VERSION="18.2.0" TYPE="HIDDEN">
	<TITLE>NI-PAL</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="ni-pal_armv7a.tar" TYPE="TAR"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{450CA255-E9A6-43B4-B86D-2B76F7057D85}" VERSION="14.0">
				<TITLE>NI-PAL Errors</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{ED0E40C9-8523-463D-B9ED-125DC2D67A62}" VERSION="14.0">
				<TITLE>NI-KAL</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{39864828-E46E-461E-8780-9C50ADA29115}" VERSION="11.0">
				<TITLE>Base System</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{B7C27E68-5D07-4679-8610-6D67381E9EFB}" VERSION="18.0.0" TYPE="VISIBLE" HIDEVERSION="YES">
	<TITLE>NI-VISA Remote Passport</TITLE>
	<ABSTRACT>The NI-VISA Remote Passport provides support for VISA applications and drivers that use remote VISA resources connected to another computer on the network.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="ni-visa-passport-remote_armv7a.tar" TYPE="TAR"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{2C9F0C7B-DB26-40B1-A078-ABFB614C013E}" VERSION="18.0.0">
				<TITLE>NI-VISA</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{BE793622-69E8-4F0F-B3AB-DB06517FF276}" VERSION="18.0" TYPE="VISIBLE">
	<TITLE>CompactRIO Support</TITLE>
	<ABSTRACT>CompactRIO Support provides NI-RIO driver support for CompactRIO controllers and chassis.</ABSTRACT>
	<IMPLEMENTATION>
		<EXCEPTPROCESSOR VALUE="775E"/>
		<EXCEPTPROCESSOR VALUE="77D6"/>
		<EXCEPTPROCESSOR VALUE="77D5"/>
		<EXCEPTPROCESSOR VALUE="77D4"/>
		<DEVICECLASS VALUE="CRIO"/>
		<DEVICECLASS VALUE="ETHERNET RIO"/>
		<OS VALUE="Linux-ARMv7-A"><OSVERSION VALUE="5.0.0"/></OS>
		<CODEBASE FILENAME="atomiczynqk.tar" TYPE="TAR"/>
		<CODEBASE FILENAME="/usr/local/natinst/nibds/clients/atomiczynqk"/>
		<CODEBASE FILENAME="/etc/modules.autoload.d/atomiczynqk"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libatomiczynqu.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libhmblv.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/English/nicrio.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/French/nicrio.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/German/nicrio.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/Japanese/nicrio.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/ChineseS/nicrio.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/English/criomdk.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/French/criomdk.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/German/criomdk.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/Japanese/criomdk.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/ChineseS/criomdk.err"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libatomiczynqu.so.18"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libatomiczynqu.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libhmblv.so.18"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libhmblv.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{56032245-0F4B-4641-9D74-33D067EB32B3}" VERSION="17.0">
				<TITLE>NI-RIO</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{F1A95C0D-8E4A-41D7-AE78-B08371D70EB4}" VERSION="14.0">
				<TITLE>NI-BDS</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{ED0E40C9-8523-463D-B9ED-125DC2D67A62}" VERSION="14.0">
				<TITLE>NI-KAL</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{39864828-E46E-461E-8780-9C50ADA29115}" VERSION="11.0">
				<TITLE>Base System</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{CAFF132A-40E3-4D34-9C2B-1664CB9E6AD5}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NIVISSVC</TITLE>
	<IMPLEMENTATION>
		<EXCEPTPROCESSOR VALUE="736B"/>
		<EXCEPTPROCESSOR VALUE="73DE"/>
		<EXCEPTPROCESSOR VALUE="75C8"/>
		<EXCEPTPROCESSOR VALUE="774C"/>
		<EXCEPTPROCESSOR VALUE="74E8"/>
		<EXCEPTPROCESSOR VALUE="774E"/>
		<OS VALUE="VxWorks-PPC603"/>
		<OS VALUE="Linux-ARMv7-A"/>
		<OS VALUE="NI-Linux x64"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{8BD4ED5E-A4AA-412E-AD58-F14178284102}" VERSION="18.0.0">
				<TITLE>NI Vision Common</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{7626BCF0-C9F4-4BD2-A6B6-DAD808625076}" VERSION="18.0.0">
				<TITLE>NIVISSVC Target Options</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{7626BCF0-C9F4-4BD2-A6B6-DAD808625076}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NIVISSVC Target Options</TITLE>
	<IMPLEMENTATION>
		<EXCEPTPROCESSOR VALUE="774C"/>
		<EXCEPTPROCESSOR VALUE="774E"/>
		<OS VALUE="Linux-ARMv7-A"/>
		<OS VALUE="NI-Linux x64"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{8BD4ED5E-A4AA-412E-AD58-F14178284102}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI Vision Common</TITLE>
	<IMPLEMENTATION>
		<EXCEPTPROCESSOR VALUE="774C"/>
		<EXCEPTPROCESSOR VALUE="774E"/>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libnivissvc.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libnivision.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libswscale.so.2.1.101"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libavutil.so.51.73.101"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libavformat.so.54.29.104"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libavcodec.so.54.59.100"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libnivisidl.so.18.0.0"/>
		<CODEBASE FILENAME="/VISION/ni_vision.ttf"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/English/nivision.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/French/nivision.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/German/nivision.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/Japanese/nivision.err"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libnivissvc.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libnivision.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libnivisidl.so.1"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libnivisidl.so"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{CB0082E2-F312-4687-9388-365868371BED}" VERSION="18.0" TYPE="VISIBLE">
	<TITLE>NI-RIO Server</TITLE>
	<ABSTRACT>This component installs the RPC Server of NI-RIO. The NI-RIO Server enables remote hosts to communicate with FPGA targets on this computer.</ABSTRACT>
	<IMPLEMENTATION>
		<DEVICECLASS VALUE="FLEXRIO"/>
		<DEVICECLASS VALUE="CRIO"/>
		<DEVICECLASS VALUE="ETHERNET RIO"/>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="NiRioServer.tar" TYPE="TAR"/>
		<SYMLINK LINK="/etc/init.d/NiRioServer"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{56032245-0F4B-4641-9D74-33D067EB32B3}" VERSION="18.0">
				<TITLE>NI-RIO</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{56032245-0F4B-4641-9D74-33D067EB32B3}" VERSION="18.0" TYPE="VISIBLE" OLDESTCOMPATIBLEVERSION="17.0">
	<TITLE>NI-RIO</TITLE>
	<ABSTRACT>The NI-RIO driver enables LabVIEW Real-Time and remote hosts to communicate with an FPGA target.</ABSTRACT>
	<IMPLEMENTATION>
		<DEVICECLASS VALUE="CRIO"/>
		<DEVICECLASS VALUE="ETHERNET RIO"/>
		<OS VALUE="Linux-ARMv7-A"><OSVERSION VALUE="2.1.0"/></OS>
		<CODEBASE FILENAME="NiRioAtomicRIO.tar" TYPE="TAR"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libNiFpga.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libNiFpgaLv.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libNiRioSrv.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libniriosae.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.FirmwareErase.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.FirmwareErase.const.de.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.FirmwareErase.const.fr.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.FirmwareErase.const.ja.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.FirmwareErase.const.ko.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.FirmwareErase.const.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.FirmwareErase.const.zh-CN.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.FirmwareErase.def.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.generalSettings.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.generalSettings.const.de.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.generalSettings.const.fr.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.generalSettings.const.ja.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.generalSettings.const.ko.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.generalSettings.const.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.generalSettings.const.zh-CN.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nirio.generalSettings.def.xml"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libNiFpga.so.18"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libNiFpga.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libNiFpgaLv.so.18"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libNiFpgaLv.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libNiRioSrv.so.18"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libNiRioSrv.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libniriosae.so.18"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libniriosae.so"/>
		<FEATURE SELECT="YESDEPS">
			<SOFTPKG NAME="{BE793622-69E8-4F0F-B3AB-DB06517FF276}" VERSION="13.0">
				<TITLE>CompactRIO Support</TITLE>
			</SOFTPKG>
		</FEATURE>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="13.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{39864828-E46E-461E-8780-9C50ADA29115}" VERSION="11.0">
				<TITLE>Base System</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{7370B6F6-DEB9-4241-8C6C-A39804097C8B}" VERSION="18.0">
				<TITLE>LabVIEW FPGA</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{5FEB7A50-4EFF-416F-9EE9-EC94006BAA66}" VERSION="5.5.0">
				<TITLE>NI System API</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{742C82AD-223A-4CCE-AFEC-55D0C1A659E7}" VERSION="2.2.2">
				<TITLE>NI-APAL</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{450CA255-E9A6-43B4-B86D-2B76F7057D85}" VERSION="2.9.1">
				<TITLE>NI-PAL Errors</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{F1A95C0D-8E4A-41D7-AE78-B08371D70EB4}" VERSION="14.0">
				<TITLE>NI-BDS</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{ED0E40C9-8523-463D-B9ED-125DC2D67A62}" VERSION="15.0">
				<TITLE>NI-KAL</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{122DEDA2-14F8-459E-BDFD-696768E253B6}" VERSION="16.0">
				<TITLE>NI-RIO FPGA Interface Driver Support</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<MERGEINI TARGET="/usr/local/natinst/share/nisysapi.ini">[NI-RIO]
Path=/usr/local/natinst/lib/libniriosae.so.18.0.0
ExportFactory=createSysApiExpert

		</MERGEINI>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{122DEDA2-14F8-459E-BDFD-696768E253B6}" VERSION="18.0" TYPE="HIDDEN">
	<TITLE>NI-RIO FPGA Interface Driver Support</TITLE>
	<ABSTRACT>NI-RIO FPGA Interface Driver Support</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libniriodevenum.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libniriosession.so.18.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libniriodevenum.so.18"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libniriodevenum.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libniriosession.so.18"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libniriosession.so"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{450CA255-E9A6-43B4-B86D-2B76F7057D85}" VERSION="18.2.0" TYPE="HIDDEN">
	<TITLE>NI-PAL Errors</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<OS VALUE="NI-Linux x64"/>
		<CODEBASE FILENAME="ni-pal-errors_all.tar" TYPE="TAR"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{7370B6F6-DEB9-4241-8C6C-A39804097C8B}" VERSION="18.0" TYPE="HIDDEN" OLDESTCOMPATIBLEVERSION="18.0">
	<TITLE>LabVIEW FPGA</TITLE>
	<ABSTRACT>Files necessary to use LabVIEW FPGA and the FPGA Interface on a RT system.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<OS VALUE="NI-Linux x64"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/English/lvfpga.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/French/lvfpga.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/German/lvfpga.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/Japanese/lvfpga.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/ChineseS/lvfpga.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/English/niriofcf.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/French/niriofcf.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/German/niriofcf.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/Japanese/niriofcf.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/ChineseS/niriofcf.err"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{742C82AD-223A-4CCE-AFEC-55D0C1A659E7}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI-APAL</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/errors/English/niapal.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/errors/Japanese/niapal.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/errors/ChineseS/niapal.err"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{CBFAAEAA-D69C-4295-A511-2988A7CEC9B4}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>Network Configuration Web Support</TITLE>
	<ABSTRACT>Network Configuration Web Support installs the NI Web-based Configuration and Monitoring Network Configuration page. Use this page to view and set the network settings for your target.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/ExtensionMetaData.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/NetworkConfig.xap"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/DisplayInfo.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/DisplayInfo.de.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/DisplayInfo.fr.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/DisplayInfo.ja.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/DisplayInfo.ko.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/DisplayInfo.zh-Hans.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/Help/en/NetworkConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/Help/de/NetworkConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/Help/fr/NetworkConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/Help/ja/NetworkConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/Help/ko/NetworkConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/Help/zh-Hans/NetworkConfigHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NetworkConfig/Images/NetworkConfigIcon.png"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{25D93C94-D8AB-4DEE-930D-7CC4B0EBB92B}" VERSION="14.0.0">
				<TITLE>NI Web-based Configuration and Monitoring</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{75BE83A6-6097-4DD3-8E3E-5D6384A1D095}" VERSION="18.0.0">
				<TITLE>WIF core dependencies</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{7E56CD7B-42D6-46E0-8638-DE2D819A3A9D}" VERSION="18.0.0">
				<TITLE>NI System API Silverlight client</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{25D93C94-D8AB-4DEE-930D-7CC4B0EBB92B}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>NI Web-based Configuration and Monitoring</TITLE>
	<ABSTRACT>Enables remote configuration and monitoring of the system from a standard Web browser.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/wif_core/WebService.ini"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/wif_core/libwif_core.so.16.0.0"/>
		<SYMLINK LINK="/var/local/natinst/webservices/NI/wif_core/libwif_core.so"/>
		<FEATURE SELECT="YESDEPS">
			<SOFTPKG NAME="{37638B3C-551E-46D4-9503-2DBBB5B1132D}">
				<TITLE>Hardware Configuration Web Support</TITLE>
			</SOFTPKG>
		</FEATURE>
		<FEATURE SELECT="YESDEPS">
			<SOFTPKG NAME="{CBFAAEAA-D69C-4295-A511-2988A7CEC9B4}">
				<TITLE>Network Configuration Web Support</TITLE>
			</SOFTPKG>
		</FEATURE>
		<FEATURE SELECT="NO">
			<SOFTPKG NAME="{0B37CBE4-E653-4A61-B098-01E097D85E24}">
				<TITLE>Network Browser Web Support</TITLE>
			</SOFTPKG>
		</FEATURE>
		<FEATURE SELECT="YESDEPS">
			<SOFTPKG NAME="{5A0FD458-F336-4749-8548-9326219BB596}">
				<TITLE>Software Management Web Support</TITLE>
			</SOFTPKG>
		</FEATURE>
		<FEATURE SELECT="YESDEPS">
			<SOFTPKG NAME="{A7E4BD0D-3E71-4ECD-B9FC-1D360BED0769}">
				<TITLE>Time Configuration Web Support</TITLE>
			</SOFTPKG>
		</FEATURE>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{AD22C016-BED0-4996-BA2C-FF6671BC4553}" VERSION="18.0.0">
				<TITLE>WIF Core</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{AD22C016-BED0-4996-BA2C-FF6671BC4553}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>WIF Core</TITLE>
	<ABSTRACT>Core WIF files shared by all platform installations</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<OS VALUE="NI-Linux x64"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF.html"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WIFCore.xap"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/ExtensionMetaData.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/FileBrowser.xap"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/DisplayInfo.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/DisplayInfo.de.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/DisplayInfo.fr.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/DisplayInfo.ja.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/DisplayInfo.ko.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/DisplayInfo.zh-Hans.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/Help/en/FileBrowserHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/Help/de/FileBrowserHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/Help/fr/FileBrowserHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/Help/ja/FileBrowserHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/Help/ko/FileBrowserHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/Help/zh-Hans/FileBrowserHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/FileBrowser/Images/FileBrowserIcon.png"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/WIFNIAuth.xap"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/DisplayInfo.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/DisplayInfo.de.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/DisplayInfo.fr.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/DisplayInfo.ja.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/DisplayInfo.ko.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/DisplayInfo.zh-Hans.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/ExtensionMetaData.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/Images/WIFNIAuthIcon.png"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/Help/en/WIFNIAuthHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/Help/de/WIFNIAuthHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/Help/fr/WIFNIAuthHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/Help/ja/WIFNIAuthHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/Help/ko/WIFNIAuthHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NIAuth/Help/zh-Hans/WIFNIAuthHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/SYSlog.xap"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/DisplayInfo.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/DisplayInfo.de.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/DisplayInfo.fr.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/DisplayInfo.ja.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/DisplayInfo.ko.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/DisplayInfo.zh-Hans.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/ExtensionMetaData.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/Images/SYSlogIcon.png"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/Help/en/SYSlogHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/Help/de/SYSlogHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/Help/fr/SYSlogHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/Help/ja/SYSlogHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/Help/ko/SYSlogHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/SYSlog/Help/zh-Hans/SYSlogHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/WebServerConfigExtension.xap"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/DisplayInfo.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/DisplayInfo.de.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/DisplayInfo.fr.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/DisplayInfo.ja.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/DisplayInfo.ko.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/DisplayInfo.zh-Hans.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/ExtensionMetaData.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/Images/WebServerConfigExtensionIcon.png"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/Help/en/WebServerConfigExtensionHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/Help/de/WebServerConfigExtensionHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/Help/fr/WebServerConfigExtensionHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/Help/ja/WebServerConfigExtensionHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/Help/ko/WebServerConfigExtensionHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServerConfigExtension/Help/zh-Hans/WebServerConfigExtensionHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/ExtensionMetaData.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/WebServicesManagement.xap"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/DisplayInfo.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/DisplayInfo.de.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/DisplayInfo.fr.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/DisplayInfo.ja.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/DisplayInfo.ko.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/DisplayInfo.zh-Hans.xml"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/Help/en/WebServicesManagementHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/Help/de/WebServicesManagementHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/Help/fr/WebServicesManagementHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/Help/ja/WebServicesManagementHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/Help/ko/WebServicesManagementHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/Help/zh-Hans/WebServicesManagementHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/WebServicesManagement/Images/WebServicesManagementIcon.png"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/add.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/arraytools.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/arrow_close.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/arrow_open.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/blueleft.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/blueright.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/box.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/caution.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/checkinstalled.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/common.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/cssframes.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/diamond.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/domtools.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/dynamiccontent.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/dynamicjumps.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/dynamiclinks.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/expandable_tree.css"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/expandable_tree.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/feedbacklink.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/find.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/hyphen.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/initpagedyn.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/jump.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/launchhelp.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/linking.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/minibutton.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/minimal.css"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/noloc_env_wif_security.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/note.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/open.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/pdf.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/placeholder.txt"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/polyviselect.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/print.css"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/stylesheets.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/support.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/tip.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/top.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/unsupport.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/variables.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Help/web.js"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Core/Help/de/ExtensionsHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Core/Help/de/WIFHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Core/Help/en/ExtensionsHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Core/Help/en/WIFHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Core/Help/fr/ExtensionsHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Core/Help/fr/WIFHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Core/Help/ja/ExtensionsHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Core/Help/ja/WIFHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Core/Help/ko/ExtensionsHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Core/Help/ko/WIFHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Core/Help/zh-Hans/ExtensionsHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/Core/Help/zh-Hans/WIFHelp.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NationalInstruments.DynamicNavigation.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NationalInstruments.Security.Cryptography.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/System.ComponentModel.DataAnnotations.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/System.Windows.Controls.Data.Input.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/System.Windows.Controls.Data.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/System.Windows.Controls.Input.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/System.Windows.Controls.Layout.Toolkit.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/System.Windows.Controls.Navigation.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/System.Windows.Controls.Toolkit.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/System.Windows.Controls.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/System.Windows.Data.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/System.Xml.Linq.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/System.Xml.Serialization.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/System.Xml.XPath.zip"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{5125BB03-DF31-4690-A87C-CF17DEF35FEA}" VERSION="14.0.0">
				<TITLE>Run-Time Engine for Web Services</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{DB69F6E1-DBDC-461E-A383-5052023409A7}" VERSION="14.0.0">
				<TITLE>RT Exec Services</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{DCE66C0D-AF78-4C84-90E5-A0729B911429}" VERSION="14.0.0">
				<TITLE>NIAuth Web Service</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{330281D5-212A-4C12-A654-37623089C3DC}" VERSION="15.0.0">
				<TITLE>NI System Log Web Service</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{035BDBDB-A575-408A-B28D-7AEB597D1123}" VERSION="14.0.0">
				<TITLE>NI System Web Server</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{1C6E0B8D-3F23-42AB-B93D-3D4BC01307F6}" VERSION="1.0">
				<TITLE>Avahi Client</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{75BE83A6-6097-4DD3-8E3E-5D6384A1D095}" VERSION="14.0.0">
				<TITLE>WIF core dependencies</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{330281D5-212A-4C12-A654-37623089C3DC}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI System Log Web Service</TITLE>
	<ABSTRACT>NI System Log Web Service</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/syslogWebService/WebService.ini"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/syslogWebService/libsyslogWebService.so.1.0.0"/>
		<SYMLINK LINK="/var/local/natinst/webservices/NI/syslogWebService/libsyslogWebService.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{5125BB03-DF31-4690-A87C-CF17DEF35FEA}" VERSION="10.0.0">
				<TITLE>Run-Time Engine for Web Services</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{75BE83A6-6097-4DD3-8E3E-5D6384A1D095}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>WIF core dependencies</TITLE>
	<ABSTRACT>WIF core dependencies</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NationalInstruments.Config.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NationalInstruments.Config.MAX.zip"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NationalInstruments.Config.SysConfig.zip"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{7E56CD7B-42D6-46E0-8638-DE2D819A3A9D}" VERSION="18.0.0">
				<TITLE>NI System API Silverlight client</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{7E56CD7B-42D6-46E0-8638-DE2D819A3A9D}" VERSION="18.1.0" TYPE="HIDDEN">
	<TITLE>NI System API Silverlight client</TITLE>
	<ABSTRACT>NI System API Silverlight client</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/var/local/natinst/www/WIF/NationalInstruments.SystemApi.zip"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{5FEB7A50-4EFF-416F-9EE9-EC94006BAA66}" VERSION="18.1.0">
				<TITLE>NI System API</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{8946D3FB-8D14-4BFC-B401-2827F86364EB}" VERSION="18.1.0">
				<TITLE>NI System Configuration Remote Support</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{E62A7BA2-8ED9-4C4A-AFA1-0DE33A188D61}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>NI-VISA Server</TITLE>
	<ABSTRACT>The NI-VISA Remote Server shares VISA resources over the network. This enables other clients with the NI-VISA Remote Passport installed to access your resources.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="ni-visa-server_armv7a.tar" TYPE="TAR"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="12.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{2C9F0C7B-DB26-40B1-A078-ABFB614C013E}" VERSION="18.0.0">
				<TITLE>NI-VISA</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{2C9F0C7B-DB26-40B1-A078-ABFB614C013E}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>NI-VISA</TITLE>
	<ABSTRACT>VISA provides an API for instrument control. This component includes the NI-VISA core and the NI-VISA Serial Passport for Serial resources. This includes both RS-232 and RS-485.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="ni-visa_armv7a.tar" TYPE="TAR"/>
		<CODEBASE FILENAME="ni-visa-data_all.tar" TYPE="TAR"/>
		<FEATURE SELECT="YESDEPS">
			<SOFTPKG NAME="{18108842-F963-4FE1-B709-1C79F745FF71}" VERSION="18.0.0">
				<TITLE>NI-VISA ENET Passport</TITLE>
			</SOFTPKG>
		</FEATURE>
		<FEATURE SELECT="YESDEPS">
			<SOFTPKG NAME="{78036FC0-F244-4AB4-9816-0A5415E3F22C}" VERSION="18.0.0">
				<TITLE>NI-VISA ENET-ASRL Passport</TITLE>
			</SOFTPKG>
		</FEATURE>
		<FEATURE SELECT="YESDEPS">
			<SOFTPKG NAME="{B7C27E68-5D07-4679-8610-6D67381E9EFB}" VERSION="18.0.0">
				<TITLE>NI-VISA Remote Passport</TITLE>
			</SOFTPKG>
		</FEATURE>
		<FEATURE SELECT="YESDEPS">
			<SOFTPKG NAME="{9992C06F-FBAC-47DE-912F-3F4A1CF6A284}" VERSION="18.0.0">
				<TITLE>NI-VISA USB Passport</TITLE>
			</SOFTPKG>
		</FEATURE>
		<FEATURE SELECT="YESDEPS">
			<SOFTPKG NAME="{E62A7BA2-8ED9-4C4A-AFA1-0DE33A188D61}" VERSION="18.0.0">
				<TITLE>NI-VISA Server</TITLE>
			</SOFTPKG>
		</FEATURE>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{89E9C488-FBB0-4934-ABF7-627E8E37CF40}" VERSION="18.0.0">
				<TITLE>NI-VISA UI XML</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{CC6559A0-9A4F-4AEA-81CF-39277C7D879D}" VERSION="18.0.0">
				<TITLE>NI-VISA Serial Passport </TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{A84EF0EF-3CFB-4ED4-9E36-CD256259B1C9}" VERSION="18.0.0">
				<TITLE>NI-VISA Error Description Files</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="12.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{5FEB7A50-4EFF-416F-9EE9-EC94006BAA66}" VERSION="16.0.0">
				<TITLE>NI System API</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{89E9C488-FBB0-4934-ABF7-627E8E37CF40}" VERSION="18.0.0" TYPE="HIDDEN" OLDESTCOMPATIBLEVERSION="14.0">
	<TITLE>NI-VISA System API Support</TITLE>
	<ABSTRACT>System API Support for NI-VISA</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="ni-visa-sysapi_armv7a.tar" TYPE="TAR"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{A84EF0EF-3CFB-4ED4-9E36-CD256259B1C9}" VERSION="18.0.0" TYPE="HIDDEN" OLDESTCOMPATIBLEVERSION="18.0">
	<TITLE>NI-VISA Error Description Files</TITLE>
	<ABSTRACT>NI-VISA Error Description Files</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="NI-Linux x64"/>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="ni-visa-errors_all.tar" TYPE="TAR"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{CC6559A0-9A4F-4AEA-81CF-39277C7D879D}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI-VISA Serial Passport</TITLE>
	<ABSTRACT>The NI-VISA Serial Passport provides support for VISA applications and drivers that use Serial resources. This includes both RS-232 and RS-485.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="ni-visa-passport-serial_armv7a.tar" TYPE="TAR"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{F1A95C0D-8E4A-41D7-AE78-B08371D70EB4}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI-BDS</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="ni-bds_armv7a.tar" TYPE="TAR"/>
		<CODEBASE FILENAME="ni-bds-nikalmod_armv7a.tar" TYPE="TAR"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{ED0E40C9-8523-463D-B9ED-125DC2D67A62}" VERSION="14.0.0">
				<TITLE>NI-KAL</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{39864828-E46E-461E-8780-9C50ADA29115}" VERSION="11.0">
				<TITLE>Base System</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{ED0E40C9-8523-463D-B9ED-125DC2D67A62}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI-KAL</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="NI-Linux x64"><OSVERSION VALUE="2.0.0"/></OS>
		<OS VALUE="Linux-ARMv7-A"><OSVERSION VALUE="2.0.0"/></OS>
		<CODEBASE FILENAME="ni-kal_all.tar" TYPE="TAR"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{39864828-E46E-461E-8780-9C50ADA29115}" VERSION="11.0">
				<TITLE>Base System</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{F8064116-D2A9-4463-9CD7-F9C464E360BB}" VERSION="18.1.0" TYPE="VISIBLE">
	<TITLE>NI System Configuration</TITLE>
	<ABSTRACT>NI System Configuration API provides libraries and other files necessary to support applications that discover and configure systems and devices.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libnisyscfg.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libmxRmCfg.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/errors/English/nisyscfg.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/errors/Japanese/nisyscfg.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/errors/ChineseS/nisyscfg.err"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libnisyscfg.so.5"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libnisyscfg.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libmxRmCfg.so.5"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libmxRmCfg.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{5FEB7A50-4EFF-416F-9EE9-EC94006BAA66}" VERSION="18.1.0">
				<TITLE>NI System API</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{FA4C4A5D-A559-4916-AB5D-ED272FA607E4}" VERSION="3.0.2" TYPE="HIDDEN" COMPATIBILITY="3.0.1">
	<TITLE>GenICam RT</TITLE>
	<ABSTRACT>The core components required to use GenICam with LabVIEW RT.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/opt/GenICam_v3_0_NI/bin/Linux32_ARM/libGCBase_gcc-4.4-arm_v3_0_NI.so"/>
		<CODEBASE FILENAME="/opt/GenICam_v3_0_NI/bin/Linux32_ARM/libGenApi_gcc-4.4-arm_v3_0_NI.so"/>
		<CODEBASE FILENAME="/opt/GenICam_v3_0_NI/bin/Linux32_ARM/libLog_gcc-4.4-arm_v3_0_NI.so"/>
		<CODEBASE FILENAME="/opt/GenICam_v3_0_NI/bin/Linux32_ARM/liblog4cpp_gcc-4.4-arm_v3_0_NI.so"/>
		<CODEBASE FILENAME="/opt/GenICam_v3_0_NI/bin/Linux32_ARM/libMathParser_gcc-4.4-arm_v3_0_NI.so"/>
		<CODEBASE FILENAME="/opt/GenICam_v3_0_NI/bin/Linux32_ARM/libGenApiTest_gcc-4.4-arm_v3_0_NI.so"/>
		<CODEBASE FILENAME="/opt/GenICam_v3_0_NI/bin/Linux32_ARM/libNodeMapData_gcc-4.4-arm_v3_0_NI.so"/>
		<CODEBASE FILENAME="/opt/GenICam_v3_0_NI/bin/Linux32_ARM/libXmlParser_gcc-4.4-arm_v3_0_NI.so"/>
		<CODEBASE FILENAME="/opt/GenICam_v3_0_NI/bin/Linux32_ARM/libCppUnit_gcc-4.4-arm_v3_0_NI.so"/>
		<CODEBASE FILENAME="/opt/GenICam_v3_0_NI/bin/Linux32_ARM/DllPluginTester_gcc-4.4-arm_v3_0_NI"/>
		<CODEBASE FILENAME="/opt/GenICam_v3_0_NI/xml/GenApi/GenApiSchema_Version_1_0.xsd"/>
		<CODEBASE FILENAME="/opt/GenICam_v3_0_NI/xml/GenApi/GenApiSchema_Version_1_1.xsd"/>
		<CODEBASE FILENAME="/opt/GenICam_v3_0_NI/xml/GenApi/GenApi_Params_h.xsl"/>
		<CODEBASE FILENAME="/opt/GenICam_v3_0_NI/xml/GenApi/GenApi_Ptr_h.xsl"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="13.0.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{035BDBDB-A575-408A-B28D-7AEB597D1123}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI System Web Server</TITLE>
	<ABSTRACT>The NI System Web Server loads NI built web services.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="systemWebServer.tar" TYPE="TAR"/>
		<CODEBASE FILENAME="/etc/natinst/appweb/NISystemWebServer.conf"/>
		<CODEBASE FILENAME="/etc/natinst/NISystemWebServer.ini.defaults"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIWebServer/mod_niauth.so.16.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIWebServer/mod_niconf.so.16.0.0"/>
		<CODEBASE FILENAME="/var/local/natinst/www/login.html"/>
		<CODEBASE FILENAME="/var/local/natinst/www/LoginPage.xap"/>
		<CODEBASE FILENAME="/var/local/natinst/www/clientaccesspolicy.xml"/>
		<SYMLINK LINK="/etc/init.d/systemWebServer"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/mod_niauth.so"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/mod_niconf.so"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{44ECF1A3-8172-437D-B955-31B46BD96F17}" VERSION="18.0.0">
				<TITLE>NIAuth</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{6B8CDAFE-4D77-4DF8-BB8F-EF0B0CF70EDE}" VERSION="14.0.0">
				<TITLE>Appweb</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{1C8F8B62-ED51-4F34-857F-436D29168FBD}" VERSION="14.0.0">
				<TITLE>Service Locator</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{CE844AFA-EE70-4CAB-A33B-F0A90C76A707}" VERSION="13.5.0">
				<TITLE>GMP</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="10.0.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{39864828-E46E-461E-8780-9C50ADA29115}" VERSION="15.0" TYPE="HIDDEN">
	<TITLE>Base System</TITLE>
	<IMPLEMENTATION>
		<PROCESSOR VALUE="76F2"/>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="base.tar" TYPE="TAR"/>
		<CODEBASE FILENAME="/usr/local/natinst/tools/module-versioning-image.squashfs"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{CCB467C9-9FD0-4A0B-A7E5-C44DD4AB60F8}" VERSION="15.0">
				<TITLE>Base System Common</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<MERGEINI TARGET="/etc/natinst/share/ni-rt.ini">[SYSTEMSETTINGS]
APMaxNumStations=6

[RTLINUXMEMRESERVE]
Base=24

		</MERGEINI>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{3F3A1E44-4835-4E83-8AF5-7229DA8B84E3}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>Web Server SSL Support for RT</TITLE>
	<ABSTRACT>Installs SSL module and management web service</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIWebServer/mod_nissl.so.16.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIWebServer/mod_ssl.so.4.1.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIWebServer/libmprssl.so.4.1.0"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/LVWSSslAdmin/WebService.ini"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/LVWSSslAdmin/libssladminsvc.so.16.0.0"/>
		<CODEBASE FILENAME="/var/local/natinst/tracelogs/sslAdminSvc.cfg"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/mod_nissl.so"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/mod_ssl.so"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/libmprssl.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libmprssl.so.4.1.0"/>
		<SYMLINK LINK="/var/local/natinst/webservices/NI/LVWSSslAdmin/libssladminsvc.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{A9AA9E46-3C43-4540-BDA0-5555C3AE8BD4}" VERSION="14.0.0">
				<TITLE>Trace Engine</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{5125BB03-DF31-4690-A87C-CF17DEF35FEA}" VERSION="14.5.0">
				<TITLE>Run-Time Engine for Web Services</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{44ECF1A3-8172-437D-B955-31B46BD96F17}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NIAuth</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIAuth/libniauth.so.16.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIAuth/libniPortableRegistry.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libniauthlocal.so.16.0.0"/>
		<CODEBASE FILENAME="nss_pam.tar" TYPE="TAR"/>
		<CODEBASE FILENAME="/var/local/natinst/tracelogs/niauth.cfg"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIAuth/libniauth.so"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIAuth/libniPortableRegistry.so"/>
		<SYMLINK LINK="/etc/init.d/niauth"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{C12BE192-909C-4C10-8D6D-3FA49C4D7DB2}" VERSION="16.0.0">
				<TITLE>NI cURL</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{39864828-E46E-461E-8780-9C50ADA29115}" VERSION="11.0.0">
				<TITLE>Base System</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{4518ADD7-D2AD-4F39-9708-51876CD166E1}" VERSION="18.0.0" TYPE="VISIBLE" OLDESTCOMPATIBLEVERSION="13.0.0">
	<TITLE>WebDAV Server</TITLE>
	<ABSTRACT>A module for the system web server that enables it to act as a WebDAV server. This allows remote access to the target's file system via a standard, IT friendly, secure protocol.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIWebServer/mod_nidav.so.16.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/mod_nidav.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{5125BB03-DF31-4690-A87C-CF17DEF35FEA}" VERSION="13.0.0">
				<TITLE>Run-Time Engine for Web Services</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{1C6E0B8D-3F23-42AB-B93D-3D4BC01307F6}" VERSION="1.0">
				<TITLE>Avahi Client</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{5125BB03-DF31-4690-A87C-CF17DEF35FEA}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>Run-Time Engine for Web Services</TITLE>
	<ABSTRACT>Allows LabVIEW VIs to be executed as Web Services.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="ws_runtime.tar" TYPE="TAR"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/LVWSSysAdmin/WebService.ini"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/LVWSSysAdmin/libsysadminsvc.so.16.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/webserver/services/LVWSDebugSvc/WebService.ini"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/webserver/services/LVWSDebugSvc/libdebugsvc.so.16.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/webserver/niwsdebugserver.conf.template"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/webserver/ws_www/login.html"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/webserver/ws_www/LoginPage.xap"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/webserver/ws_www/clientaccesspolicy.xml"/>
		<CODEBASE FILENAME="/etc/natinst/webservices/webservices.ini"/>
		<CODEBASE FILENAME="/var/local/natinst/tracelogs/ws_shared.cfg"/>
		<CODEBASE FILENAME="/var/local/natinst/tracelogs/ws_runtime.cfg"/>
		<CODEBASE FILENAME="/var/local/natinst/tracelogs/mod_niws.cfg"/>
		<CODEBASE FILENAME="/var/local/natinst/tracelogs/ws_service_container.cfg"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/libws_runtime.so"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/ws_runtime.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libws_runtime.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libws_runtime.so.16.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/lib/ws_runtime.so"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/mod_niws.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libmod_niws.so.16.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/libws_repl.so"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/ws_repl.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libws_repl.so.16.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/lib/ws_repl.so"/>
		<SYMLINK LINK="/var/local/natinst/webservices/NI/LVWSSysAdmin/libsysadminsvc.so"/>
		<SYMLINK LINK="/usr/local/natinst/labview/webserver/services/LVWSDebugSvc/libdebugsvc.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{A9AA9E46-3C43-4540-BDA0-5555C3AE8BD4}" VERSION="14.0.0">
				<TITLE>Trace Engine</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{035BDBDB-A575-408A-B28D-7AEB597D1123}" VERSION="14.0.0">
				<TITLE>NI System Web Server</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{6B8CDAFE-4D77-4DF8-BB8F-EF0B0CF70EDE}" VERSION="18.0.0" TYPE="HIDDEN" OLDESTCOMPATIBLEVERSION="13.0.0">
	<TITLE>Appweb</TITLE>
	<ABSTRACT>Installs libappweb, its modules (libcopymodule, libespmodule, libdirmodule) and mime.types.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIWebServer/libpcre.so.4.1.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIWebServer/libmpr.so.4.1.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIWebServer/libhttp.so.4.1.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIWebServer/libappwebcore.so.4.1.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIWebServer/mod_niesp.so.16.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIWebServer/mod_nisessmgr.so.16.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/NIWebServer/libappweb.so.16.0.0"/>
		<CODEBASE FILENAME="/etc/natinst/mime.types"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/libpcre.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libpcre.so.4.1.0"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/libmpr.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libmpr.so.4.1.0"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/libhttp.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libhttp.so.4.1.0"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/libappwebcore.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libappwebcore.so.4.1.0"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/mod_niesp.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libmod_niesp.so.16.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/mod_nisessmgr.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libmod_nisessmgr.so.16.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/share/NIWebServer/libappweb.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{DB78A098-8647-4E3B-9F12-C3234699234C}" VERSION="14.0.0">
				<TITLE>SSL Support for LabVIEW RT</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{8946D3FB-8D14-4BFC-B401-2827F86364EB}" VERSION="18.1.0" TYPE="VISIBLE">
	<TITLE>NI System Configuration Remote Support</TITLE>
	<ABSTRACT>NI System Configuration Remote Support provides web services for network discovery and configuration.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/nisysapi/libnisysapisvc.so.18.0.0"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/nisysapi/WebService.ini"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationExt.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationExt.const.de.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationExt.const.fr.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationExt.const.ja.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationExt.const.ko.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationExt.const.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationExt.const.zh-CN.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationExt.def.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationInt.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationInt.const.de.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationInt.const.fr.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationInt.const.ja.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationInt.const.ko.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationInt.const.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationInt.const.zh-CN.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.CalibrationInt.def.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.Device.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.Device.const.de.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.Device.const.fr.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.Device.const.ja.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.Device.const.ko.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.Device.const.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.Device.const.zh-CN.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.Device.def.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.DiagnosticReset.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.DiagnosticReset.def.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.DiagnosticSelfTest.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.DiagnosticSelfTest.def.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.FirmwareUpdate.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.FirmwareUpdate.const.de.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.FirmwareUpdate.const.fr.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.FirmwareUpdate.const.ja.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.FirmwareUpdate.const.ko.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.FirmwareUpdate.const.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.FirmwareUpdate.const.zh-CN.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.FirmwareUpdate.def.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.ModuleProgramMode.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.ModuleProgramMode.const.de.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.ModuleProgramMode.const.fr.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.ModuleProgramMode.const.ja.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.ModuleProgramMode.const.ko.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.ModuleProgramMode.const.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.ModuleProgramMode.const.zh-CN.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.ModuleProgramMode.def.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.NetworkDevice.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.NetworkDevice.const.de.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.NetworkDevice.const.fr.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.NetworkDevice.const.ja.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.NetworkDevice.const.ko.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.NetworkDevice.const.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.NetworkDevice.const.zh-CN.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.NetworkDevice.def.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.PciPxiDevice.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.PciPxiDevice.const.de.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.PciPxiDevice.const.fr.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.PciPxiDevice.const.ja.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.PciPxiDevice.const.ko.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.PciPxiDevice.const.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.PciPxiDevice.const.zh-CN.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.PciPxiDevice.def.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.RenamableDevice.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.RenamableDevice.const.de.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.RenamableDevice.const.fr.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.RenamableDevice.const.ja.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.RenamableDevice.const.ko.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.RenamableDevice.const.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.RenamableDevice.const.zh-CN.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.RenamableDevice.def.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.soft_dip_switch.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.soft_dip_switch.def.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.System.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.System.const.de.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.System.const.fr.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.System.const.ja.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.System.const.ko.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.System.const.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.System.const.zh-CN.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.System.def.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.SystemRsrc.binding.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.SystemRsrc.const.de.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.SystemRsrc.const.fr.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.SystemRsrc.const.ja.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.SystemRsrc.const.ko.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.SystemRsrc.const.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.SystemRsrc.const.zh-CN.xml"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/uixml/sysconfig/nisyscfg.SystemRsrc.def.xml"/>
		<SYMLINK LINK="/var/local/natinst/webservices/NI/nisysapi/libnisysapisvc.so.5"/>
		<SYMLINK LINK="/var/local/natinst/webservices/NI/nisysapi/libnisysapisvc.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{5FEB7A50-4EFF-416F-9EE9-EC94006BAA66}" VERSION="18.1.0">
				<TITLE>NI System API</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{C1302D32-5344-4392-AF25-21AA18FD1535}" VERSION="18.0.0">
				<TITLE>Software Installation WebService</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="13.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{5125BB03-DF31-4690-A87C-CF17DEF35FEA}" VERSION="13.0">
				<TITLE>Run-Time Engine for Web Services</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{DCE66C0D-AF78-4C84-90E5-A0729B911429}" VERSION="15.0">
				<TITLE>NIAuth Web Service</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{C12BE192-909C-4C10-8D6D-3FA49C4D7DB2}" VERSION="15.0">
				<TITLE>NI cURL</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{1C6E0B8D-3F23-42AB-B93D-3D4BC01307F6}" VERSION="1.0">
				<TITLE>Avahi Client</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>LabVIEW Real-Time</TITLE>
	<ABSTRACT>LabVIEW Real-Time provides the core Real-Time Engine. You must have this component installed to be able to use any other software component.</ABSTRACT>
	<IMPLEMENTATION>
		<PROCESSOR VALUE="762F"/>
		<PROCESSOR VALUE="76D3"/>
		<PROCESSOR VALUE="76D6"/>
		<PROCESSOR VALUE="76F2"/>
		<PROCESSOR VALUE="7740"/>
		<PROCESSOR VALUE="7741"/>
		<PROCESSOR VALUE="7742"/>
		<PROCESSOR VALUE="7743"/>
		<PROCESSOR VALUE="7744"/>
		<PROCESSOR VALUE="774C"/>
		<PROCESSOR VALUE="774E"/>
		<PROCESSOR VALUE="775E"/>
		<PROCESSOR VALUE="77AC"/>
		<PROCESSOR VALUE="77B1"/>
		<PROCESSOR VALUE="77B2"/>
		<PROCESSOR VALUE="77D4"/>
		<PROCESSOR VALUE="77D5"/>
		<PROCESSOR VALUE="77D6"/>
		<PROCESSOR VALUE="7885"/>
		<PROCESSOR VALUE="793C"/>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/lvanlys.so"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/lvblas.so"/>
		<FEATURE SELECT="TARGET">
			<SOFTPKG NAME="{C2C6AE73-0028-4750-B472-51C2E65DB3F9}" VERSION="18.0.0">
				<TITLE>Language Support for Japanese</TITLE>
			</SOFTPKG>
		</FEATURE>
		<FEATURE SELECT="TARGET">
			<SOFTPKG NAME="{2B13BEDE-7BA9-4A80-B2AD-334A942510B1}" VERSION="18.0.0">
				<TITLE>Language Support for Simplified Chinese</TITLE>
			</SOFTPKG>
		</FEATURE>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{CAEAE9D7-F7D3-4EA5-957E-6F09F764EE3B}" VERSION="18.0.0">
				<TITLE>LabVIEW RT Common</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{C12BE192-909C-4C10-8D6D-3FA49C4D7DB2}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI cURL</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libcurlimpl.so.18.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/share/nicurl/libcurlimpl.so.18.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/share/nicurl/libcurlimpl.so"/>
		<SYMLINK LINK="/usr/local/natinst/share/nicurl/ca-bundle.crt"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{DB78A098-8647-4E3B-9F12-C3234699234C}" VERSION="14.0.0">
				<TITLE>SSL Support for LabVIEW RT</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{EF3A1C90-8785-11E3-BAA7-0800200C9A66}" VERSION="14.0.0">
				<TITLE>NI Trusted CA Certificates</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{C1302D32-5344-4392-AF25-21AA18FD1535}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>Software Installation WebService</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/siws/libSoftwareInstallWebService.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libSoftwareActionServices.so.18.0.0"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/siws/WebService.ini"/>
		<SYMLINK LINK="/var/local/natinst/webservices/NI/siws/libSoftwareInstallWebService.so.5"/>
		<SYMLINK LINK="/var/local/natinst/webservices/NI/siws/libSoftwareInstallWebService.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libSoftwareActionServices.so.5"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libSoftwareActionServices.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{5125BB03-DF31-4690-A87C-CF17DEF35FEA}" VERSION="13.0">
				<TITLE>Run-Time Engine for Web Services</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{1C6E0B8D-3F23-42AB-B93D-3D4BC01307F6}" VERSION="18.0.0">
				<TITLE>Avahi Client</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{CAEAE9D7-F7D3-4EA5-957E-6F09F764EE3B}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>LabVIEW RT Common</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/liblvpidtkt.so.17.0.0"/>
		<CODEBASE FILENAME="lvrt.tar" TYPE="TAR"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/lvrt"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/liblvrt.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/libNILVRuntimeManager.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/english/rtapp.rsc"/>
		<CODEBASE FILENAME="/etc/natinst/labview.dir"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/liblvalarms.so.11.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/tdtable.tdr"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/English/labview.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/English/analysis.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/English/measure.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/English/reports.err"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/errors/English/Services.err"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/beyond.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/docs.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/index.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/overview.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/services.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/webtool.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/vis.htm"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/www.css"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/favicon.ico"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/images/home.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/images/homed.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/images/lvwebsrv.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/images/next.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/images/nextd.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/images/panel.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/images/panldiag.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/images/prev.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/images/prevd.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/images/top.gif"/>
		<CODEBASE FILENAME="/var/local/natinst/labview/www/images/up.gif"/>
		<SYMLINK LINK="/usr/local/natinst/lib/liblvpidtkt.so"/>
		<SYMLINK LINK="/etc/init.d/nilvrt"/>
		<SYMLINK LINK="/etc/init.d/lvrt-wrapper"/>
		<SYMLINK LINK="/usr/local/natinst/labview/liblvrt.so.18.0"/>
		<SYMLINK LINK="/usr/local/natinst/labview/libNILVRuntimeManager.so.18.0"/>
		<SYMLINK LINK="/usr/local/natinst/labview/libNILVRuntimeManager.so"/>
		<SYMLINK LINK="/usr/local/natinst/labview/liblvalarms.so.11"/>
		<SYMLINK LINK="/usr/local/natinst/labview/liblvalarms.so"/>
		<SYMLINK LINK="/usr/local/natinst/labview/libappweb.so"/>
		<SYMLINK LINK="/c/ni-rt/startup"/>
		<SYMLINK LINK="/C"/>
		<SYMLINK LINK="/home/lvuser/README_File_Paths.txt"/>
		<SYMLINK LINK="/home/lvuser/natinst/bin/README_File_Paths.txt"/>
		<SYMLINK LINK="/c/README_File_Paths.txt"/>
		<SYMLINK LINK="/c/README_File_Transfer.txt"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{AE3C452B-0C83-463C-9F5E-571E412F07F3}" VERSION="6.0">
				<TITLE>Deterministic FIFO Support for LabVIEW RT</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{B040DA53-2C8C-4FA6-A313-26036C633C98}" VERSION="18.0">
				<TITLE>NI CPU Info</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{32BC46CD-BF4A-4A57-AD90-E9A56ADD55CB}" VERSION="6.0">
				<TITLE>Deterministic Shared Variable Support for LabVIEW RT</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{39864828-E46E-461E-8780-9C50ADA29115}" VERSION="13.0">
				<TITLE>Base System</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{0F5647A4-671E-11E1-8BCD-ADCC4824019B}" VERSION="3.0">
				<TITLE>Locale Support for Latin1</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{1C8F8B62-ED51-4F34-857F-436D29168FBD}" VERSION="1.0">
				<TITLE>Service Locator</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{F94E7627-BDFA-47F8-90A6-9C7C84670AC6}" VERSION="2.5.0">
				<TITLE>TDMS File Format</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{10333BDF-D6B2-479E-915B-73F8E1C1FB8A}" VERSION="1.0.0">
				<TITLE>NI System Logging</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<MERGEINI TARGET="/etc/natinst/share/ni-rt.ini">[LVRT]
RTTarget.RTProtocolAllowed=True

[SUPPORTED LOCALES]
english=L1

		</MERGEINI>
		<MERGEINI TARGET="/etc/natinst/share/lvrt.conf">[LVRT]
thpolicy_tcrit=fifo
thpri_tcrit=94
thpolicy_vhigh=rr
thpri_vhigh=6
thpolicy_high=rr
thpri_high=5
RTCPULoadMonitoringEnabled=True
RTMode=True
appFont="paratype-pt sans" 12
dialogFont="paratype-pt sans" 12
systemFont="paratype-pt sans" 12

		</MERGEINI>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{CCB467C9-9FD0-4A0B-A7E5-C44DD4AB60F8}" VERSION="15.0" TYPE="HIDDEN" OLDESTCOMPATIBLEVERSION="15.0">
	<TITLE>Base System Common</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"><OSVERSION VALUE="3.0.0"/></OS>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libni_emb.so.11.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libni_emb.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{632D9B04-D3DD-4378-886D-5D67B61811FB}" VERSION="2.0">
				<TITLE>RT mDNS Daemon</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{1C8F8B62-ED51-4F34-857F-436D29168FBD}" VERSION="14.0.0">
				<TITLE>Service Locator</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{C1302D32-5344-4392-AF25-21AA18FD1535}" VERSION="5.5.0">
				<TITLE>Software Installation WebService</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{8946D3FB-8D14-4BFC-B401-2827F86364EB}" VERSION="5.5.0">
				<TITLE>NI System Configuration Remote Support</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{A79357A4-FC7B-41F2-888E-386FCFE83008}" VERSION="2.5.0">
				<TITLE>LabVIEW RT Error Logging</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{DB69F6E1-DBDC-461E-A383-5052023409A7}" VERSION="14.0.0">
				<TITLE>RT Exec Services</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{4518ADD7-D2AD-4F39-9708-51876CD166E1}" VERSION="14.0.0">
				<TITLE>WebDAV Server</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{2012A26D-F138-4EBB-A9B6-1EDC8E2D591E}" VERSION="1.0">
				<TITLE>Module Versioning Tools</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{DB69F6E1-DBDC-461E-A383-5052023409A7}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>RT Exec Services</TITLE>
	<ABSTRACT>RESTful web service API to a target's rt_exec functionality.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/rtexecsvc/WebService.ini"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/rtexecsvc/librtexecsvc.so.16.0.0"/>
		<SYMLINK LINK="/var/local/natinst/webservices/NI/rtexecsvc/librtexecsvc.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{5125BB03-DF31-4690-A87C-CF17DEF35FEA}" VERSION="14.0.0">
				<TITLE>Run-Time Engine for Web Services</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{DB78A098-8647-4E3B-9F12-C3234699234C}" VERSION="18.0.0" TYPE="VISIBLE">
	<TITLE>SSL Support for LabVIEW RT</TITLE>
	<ABSTRACT>SSL support.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libnisslinit.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libssleay32.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libeay32.so.18.0.0"/>
		<CODEBASE FILENAME="nissl_installer_scripts.tar" TYPE="TAR"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libssleay32.so"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libeay32.so"/>
		<SYMLINK LINK="/usr/local/natinst/share/nissl/libssleay32.so.18.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/share/nissl/libssleay32.so"/>
		<SYMLINK LINK="/usr/local/natinst/share/nissl/libeay32.so.18.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/share/nissl/libeay32.so"/>
		<SYMLINK LINK="/usr/local/natinst/share/nissl/libnisslinit.so.18.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/share/nissl/libnisslinit.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{A9AA9E46-3C43-4540-BDA0-5555C3AE8BD4}" VERSION="14.0.0">
				<TITLE>Trace Engine</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{3F3A1E44-4835-4E83-8AF5-7229DA8B84E3}" VERSION="18.0.0">
				<TITLE>Web Server SSL Support for RT</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{DCE66C0D-AF78-4C84-90E5-A0729B911429}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NIAuth Web Service</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/LVWSAuthSvc/WebService.ini"/>
		<CODEBASE FILENAME="/var/local/natinst/webservices/NI/LVWSAuthSvc/libniauthsvc.so.16.0.0"/>
		<SYMLINK LINK="/var/local/natinst/webservices/NI/LVWSAuthSvc/libniauthsvc.so"/>
		<DEPENDENCY TYPE="STRICT">
			<SOFTPKG NAME="{44ECF1A3-8172-437D-B955-31B46BD96F17}" VERSION="18.0.0">
				<TITLE>NIAuth</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{5125BB03-DF31-4690-A87C-CF17DEF35FEA}" VERSION="14.0.0">
				<TITLE>Run-Time Engine for Web Services</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{0F5647A4-671E-11E1-8BCD-ADCC4824019B}" VERSION="3.0" TYPE="HIDDEN" OLDESTCOMPATIBLEVERSION="3.0">
	<TITLE>Locale Support for Latin1</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="linux_L1.tar" TYPE="TAR"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{10333BDF-D6B2-479E-915B-73F8E1C1FB8A}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI System Logging</TITLE>
	<ABSTRACT>Allows LabVIEW applications to write messages to the system log.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/libsystemLogging.so.1.1.0"/>
		<SYMLINK LINK="/usr/local/natinst/labview/libsystemLogging.so"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{1C8F8B62-ED51-4F34-857F-436D29168FBD}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>Service Locator</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="nisvcloc.tar" TYPE="TAR"/>
		<SYMLINK LINK="/etc/init.d/nisvcloc"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{2012A26D-F138-4EBB-A9B6-1EDC8E2D591E}" VERSION="5.0" TYPE="HIDDEN">
	<TITLE>Module Versioning Tools</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/tools/tools-squashfs-image.squashfs"/>
		<CODEBASE FILENAME="versioning_utils.tar" TYPE="TAR"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{32BC46CD-BF4A-4A57-AD90-E9A56ADD55CB}" VERSION="6.0" TYPE="HIDDEN">
	<TITLE>Deterministic Shared Variable Support for LabVIEW RT</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/librtvarsup.so.6.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/labview/librtvarsup.so.6"/>
		<SYMLINK LINK="/usr/local/natinst/labview/librtvarsup.so"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{5FEB7A50-4EFF-416F-9EE9-EC94006BAA66}" VERSION="18.1.0" TYPE="HIDDEN">
	<TITLE>NI System API</TITLE>
	<ABSTRACT>NI System API</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/bin/lsni"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/nisysapi/libnisysapi.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/nisysapi/libnisyscfgExpert.so.18.0.0"/>
		<CODEBASE FILENAME="/usr/local/natinst/share/nisysapi/timezone.ini"/>
		<CODEBASE FILENAME="/var/local/natinst/systemsettings/scs_imagemetadata_redirected.ini"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libnisysapi.so.1"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libnisysapi.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{899452D2-C085-430B-B76D-7FDB33BB324A}" VERSION="13.0">
				<TITLE>LabVIEW Real-Time</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<DEPENDENCY>
			<SOFTPKG NAME="{79BBD504-B94E-4D53-A2D0-28983B2BD2C4}" VERSION="3.0">
				<TITLE>Target Configuration</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<MERGEINI TARGET="/usr/local/natinst/share/nisysapi.ini">[NISYSCFGEXPERT]
Path=/usr/local/natinst/share/nisysapi/libnisyscfgExpert.so.18.0.0
ExpertFactory=createSystemConfigBuiltInExpert

		</MERGEINI>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{632D9B04-D3DD-4378-886D-5D67B61811FB}" VERSION="6.0" TYPE="HIDDEN" OLDESTCOMPATIBLEVERSION="2.0">
	<TITLE>RT mDNS Daemon</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="nirtmdnsd.tar" TYPE="TAR"/>
		<SYMLINK LINK="/etc/init.d/nirtmdnsd"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{1C6E0B8D-3F23-42AB-B93D-3D4BC01307F6}" VERSION="1.0">
				<TITLE>Avahi Client</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{1C6E0B8D-3F23-42AB-B93D-3D4BC01307F6}" VERSION="18.1.0.2014" TYPE="HIDDEN">
	<TITLE>Avahi Client</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libniAvahiClient.so.17.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libniAvahiClient.so.14"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{39864828-E46E-461E-8780-9C50ADA29115}" VERSION="11.0">
				<TITLE>Base System</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{79BBD504-B94E-4D53-A2D0-28983B2BD2C4}" VERSION="5.0" TYPE="HIDDEN">
	<TITLE>Target Configuration</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libnitargetcfg.so.5.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libnitargetcfg.so.1"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libnitargetcfg.so"/>
		<DEPENDENCY>
			<SOFTPKG NAME="{39864828-E46E-461E-8780-9C50ADA29115}" VERSION="10.0">
				<TITLE>Base System</TITLE>
			</SOFTPKG>
		</DEPENDENCY>
		<MERGEINI TARGET="/etc/natinst/share/ni-rt.ini">[SUPPORTEDWIRELESSSECURITYTYPES]
Open=True
WEP=True
WPA_PSK=True
WPA_EAP=True
WPA2_PSK=True
WPA2_EAP=True

		</MERGEINI>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{A79357A4-FC7B-41F2-888E-386FCFE83008}" VERSION="2.7.0" TYPE="HIDDEN">
	<TITLE>LabVIEW RT Error Logging</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libni_rtlog.so.2.7.0"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libni_rtlog.so.2"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{A9AA9E46-3C43-4540-BDA0-5555C3AE8BD4}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>Trace Engine</TITLE>
	<ABSTRACT>Trace Engine collates and outputs debug trace messages from any component that uses it.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="traceengine.tar" TYPE="TAR"/>
		<CODEBASE FILENAME="/var/local/natinst/tracelogs/traceengine.ini"/>
		<SYMLINK LINK="/usr/local/natinst/share/traceengine/libni_traceengine.so"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{AE3C452B-0C83-463C-9F5E-571E412F07F3}" VERSION="6.0" TYPE="HIDDEN">
	<TITLE>Deterministic FIFO Support for LabVIEW RT</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/libnbfifo.so.6.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/labview/libnbfifo.so.6"/>
		<SYMLINK LINK="/usr/local/natinst/labview/libnbfifo.so"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{B040DA53-2C8C-4FA6-A313-26036C633C98}" VERSION="18.0" TYPE="HIDDEN">
	<TITLE>NI CPU Info</TITLE>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/labview/libniCPULib.so.18.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/labview/libniCPULib.so.18"/>
		<SYMLINK LINK="/usr/local/natinst/labview/libniCPULib.so"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{CE844AFA-EE70-4CAB-A33B-F0A90C76A707}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>GMP</TITLE>
	<ABSTRACT>NI Implementation of GMP</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libnigmp.so.5.0.1"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libnigmp.so"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{EF3A1C90-8785-11E3-BAA7-0800200C9A66}" VERSION="18.0.0" TYPE="HIDDEN">
	<TITLE>NI Trusted CA Certificates</TITLE>
	<ABSTRACT>NI Trusted CA Certificates</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<OS VALUE="NI-Linux x64"/>
		<CODEBASE FILENAME="/etc/natinst/nissl/ca-bundle.crt"/>
	</IMPLEMENTATION>
</SOFTPKG>
<SOFTPKG NAME="{F94E7627-BDFA-47F8-90A6-9C7C84670AC6}" VERSION="18.0.0.0" TYPE="HIDDEN">
	<TITLE>TDMS File Format</TITLE>
	<ABSTRACT>This component adds support for the TDMS file format. TDMS is used to share measured data amongst NI software applications.</ABSTRACT>
	<IMPLEMENTATION>
		<OS VALUE="Linux-ARMv7-A"/>
		<CODEBASE FILENAME="/usr/local/natinst/lib/libtdms.so.18.0.0"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libtdms.so.18"/>
		<SYMLINK LINK="/usr/local/natinst/lib/libtdms.so"/>
	</IMPLEMENTATION>
</SOFTPKG>
</INSTALLATION>
