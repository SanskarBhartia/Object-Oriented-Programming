//

#ifndef _ECS36B_EXCEPTION_
#define _ECS36B_EXCEPTION_

using namespace std;

class ecs36b_Exception : public exception
{
private:
protected:
public:
  std::string reason;
  ecs36b_Exception(std::string r) {
    if (r.empty())
      reason = "unknown";
    else
      reason = r;
  }
  ~ecs36b_Exception() throw () {};
  virtual const char* what() const throw () { return reason.c_str(); };
};

#endif /* _ECS36B_EXCEPTION_ */
