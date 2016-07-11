#MyRedis
##2016-6-19
###add saveRdbToFile command   
change the redisCommandTable from server.c  
add a func (saveRdbToFileCommand) define in server.h  
add a func (saveRdbToFileCommand)  in server.h  

##2016-6-20
###add readrdbfromfile command  
change the redisCommandTable from server.c  
add a func (readrdbfromfile) define in server.h   
add a func(readrdbfromfile) in server.h  
```	
	initDB();   //自己写的方法，重新分配了db的内存空间  
	rdbLoad(c->argv[1]->ptr);//redis原生方法  
	c->db=&server.db[0];//因为clint中保存了当前db的信息，所以要刷新一下client.db，否则重新连接client才会显示修改  
	rdbSaveBackground(server.rdb_filename);//做一次bgsave  
	addReplyStatus(c,"read success!now in the db 0!");   
```	

##2016-6-21
###add bgrewriteaofCommand in readrdbfromfile  
because when we run readrdbfromfile,the file appendonly.aof is not change until we run bgrewriteaof


##2016-7-11  
###在redisDb中新增了一个域，stack  
这个域里面放的就是回溯队列，具体的实现就在stack.c和stack.h中，注意要在Makefile中增加stack.o要不然不会去编译。  
