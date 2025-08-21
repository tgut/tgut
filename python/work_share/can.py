#安装依赖pip install python-can
import can

# 创建 CAN 总线对象（以 SocketCAN 为例，适用于 Linux）
bus = can.interface.Bus(channel='can0', bustype='socketcan')

# 发送一条 CAN 消息
msg = can.Message(arbitration_id=0x123, data=[0x11, 0x22, 0x33, 0x44], is_extended_id=False)
bus.send(msg)

# 接收 CAN 消息
received_msg = bus.recv(timeout=1.0)
if received_msg:
    print(f"Received: {received_msg}")

# 关闭总线
bus.shutdown()