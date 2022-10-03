//find file length and open it and send it
void sendfile(int cfd,std::string filename){
int filesize=std::__fs::filesystem::file_size(filename);
std::string buffer;
std::string sendheader="HTTP/1.1 200 OK \n Connection: keep-alive \n Content-Type: text/html \n Content-Length: "+std::to_string(filesize)+"\n\n ";
send(cfd,sendheader.c_str(),sendheader.length(), 0);
std::ifstream Myfile;
Myfile.open(filename,std::ios::in); 
while(getline(Myfile,buffer)){
send(cfd,buffer.c_str(),buffer.length(),0);
}
std::cout<<"\n"<<std::__fs::filesystem::file_size(filename);
Myfile.close();
}
