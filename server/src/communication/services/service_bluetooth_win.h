#pragma once

#include <WinSock2.h>
#include <bluetoothapis.h>

#include <atomic>
#include <string>

#include "communication/services/communication_service.h"

#include "opengloves_interface.h"

class BluetoothCommunicationService : public ICommunicationService {
 public:
  explicit BluetoothCommunicationService(og::DeviceBluetoothCommunicationConfiguration configuration);

  bool ReceiveNextPacket(std::string& buff) override;
  bool RawWrite(const std::string& buff) override;

  bool IsConnected() override;

  bool PurgeBuffer() override;

  std::string GetIdentifier() override;

  ~BluetoothCommunicationService() override;

 private:
  bool Connect();

  void LogError(const std::string&, bool with_win_error) const;

  og::DeviceBluetoothCommunicationConfiguration configuration_;

  SOCKET sock_{};

  std::atomic<bool> is_connected_;
  std::atomic<bool> is_disconnecting_;
};