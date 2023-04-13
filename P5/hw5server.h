/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_HW5SERVER_H_
#define JSONRPC_CPP_STUB_HW5SERVER_H_

#include <jsonrpccpp/server.h>

class hw5Server : public jsonrpc::AbstractServer<hw5Server>
{
    public:
        hw5Server(jsonrpc::AbstractServerConnector &conn, jsonrpc::serverVersion_t type = jsonrpc::JSONRPC_SERVER_V2) : jsonrpc::AbstractServer<hw5Server>(conn, type)
        {
            this->bindAndAddMethod(jsonrpc::Procedure("move", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "action",jsonrpc::JSON_STRING,"class_id",jsonrpc::JSON_STRING,"json_object",jsonrpc::JSON_OBJECT,"location",jsonrpc::JSON_OBJECT,"object_id",jsonrpc::JSON_STRING, NULL), &hw5Server::moveI);
            this->bindAndAddMethod(jsonrpc::Procedure("done", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT,  NULL), &hw5Server::doneI);
        }

        inline virtual void moveI(const Json::Value &request, Json::Value &response)
        {
            response = this->move(request["action"].asString(), request["class_id"].asString(), request["json_object"], request["location"], request["object_id"].asString());
        }
        inline virtual void doneI(const Json::Value &request, Json::Value &response)
        {
            (void)request;
            response = this->done();
        }
        virtual Json::Value move(const std::string& action, const std::string& class_id, const Json::Value& json_object, const Json::Value& location, const std::string& object_id) = 0;
        virtual Json::Value done() = 0;
};

#endif //JSONRPC_CPP_STUB_HW5SERVER_H_
