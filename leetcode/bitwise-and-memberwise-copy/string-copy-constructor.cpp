class String{
public:
    String(const String &other);    // copy constructor
private:
    char *m_data;    // store string data
};

String(const String &other){
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
}