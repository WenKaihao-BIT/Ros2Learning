import rclpy
from rclpy.node import Node
from std_msgs.msg import String,UInt32


class WriterNode(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info("i am %s."%name)
        self.pub_novel=self.create_publisher(String,"Chinese",10) 
        self.timer_period=5
        self.timer=self.create_timer(self.timer_period,self.timer_callback)
        self.account=80
        self.sub_monety=self.create_subscription(UInt32,"Chinese_money",self.recv_money_callback,10)
        pass
    def recv_money_callback(self,money):
        self.account+=money.data
        self.get_logger().info("收到了%d的稿费，账户余额为%d"%(money.data,self.account))

        pass
    def timer_callback(self):
        msg=String()
        msg.data=" i am your father"
        self.pub_novel.publish(msg) 
        self.get_logger().info("发布话题ing,内容为%s"%msg.data)
        pass


def main(args=None):
    #初始化客户端库
    rclpy.init(args=args)
    #创建节点
    li4_node=WriterNode("li4")
    rclpy.spin(li4_node)
    rclpy.shutdown()


