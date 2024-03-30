#include "rclcpp/rclcpp.hpp"
#include"std_msgs/msg/string.hpp"
#include"std_msgs/msg/u_int32.hpp"

using std::placeholders::_1;
class Reader:public rclcpp::Node{
    public:
    Reader(std::string name):Node(name){
        RCLCPP_INFO(this->get_logger(),"i am wang2");
        sub_novel=this->create_subscription<std_msgs::msg::String>("Chinese",10,std::bind(&Reader::novel_callback,this,_1));
        pub_money=this->create_publisher<std_msgs::msg::UInt32>("Chinese_money",10);
    }
    private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_novel;
    rclcpp::Publisher<std_msgs::msg::UInt32>::SharedPtr pub_money;
    void novel_callback(const std_msgs::msg::String::SharedPtr novels){
        std_msgs::msg::UInt32 money;
        money.data=10;
        pub_money->publish(money);
        RCLCPP_INFO(this->get_logger(),"i receive%s",novels->data.c_str());
    }
};




int main(int argc,char**argv){
    rclcpp::init(argc,argv);
    auto node =std::make_shared<Reader>("wang2");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
