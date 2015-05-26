#include <zookeeper.h>
#include <zookeeper_log.h>
#include <stdio.h>
#include <unistd.h>

void QueryServer_watcher_g(zhandle_t* zh, int type, int state,
		const char* path, void* watcherCtx)
{
	printf("wather type:%d,state:%d,path:%s,watcherCtx:%s\n",type,state,path,watcherCtx);
	if (type == ZOO_SESSION_EVENT) {
		if (state == ZOO_CONNECTED_STATE) {
			printf("[[[QueryServer]]] Connected to zookeeper service successfully!\n");
		} else if (state == ZOO_EXPIRED_SESSION_STATE) { 
			printf("Zookeeper session expired!\n");
		}
	} 
}


void QueryServer_string_completion(int rc, const char *name, const void *data)
{
	fprintf(stderr, "[%s]: rc = %d\n", (char*)(data==0?"null":data), rc);
	if (!rc) {
		fprintf(stderr, "\tname = %s\n", name);
	}
}


int main(){

	const char* host = "127.0.0.1:2181";
	int timeout = 30000;
	char* context = "hello zookeeper";

	zoo_set_debug_level(ZOO_LOG_LEVEL_WARN);
	zhandle_t* zkhandle = zookeeper_init(host,QueryServer_watcher_g, timeout, NULL, context, 0);	
	if (zkhandle == NULL) {
		printf("Error when connecting to zookeeper servers...\n");
		exit(EXIT_FAILURE);
	}

	/*int ret = zoo_acreate(zkhandle, "/QueryServer", "alive", 5,
			&ZOO_OPEN_ACL_UNSAFE, ZOO_EPHEMERAL,
			QueryServer_string_completion, "zoo_acreate");
	*/

	int ret = zoo_acreate(zkhandle, "/QueryServer/", "alive", 5,
                        &ZOO_OPEN_ACL_UNSAFE,ZOO_EPHEMERAL|ZOO_SEQUENCE,
                        QueryServer_string_completion, "zoo_acreate");
	if (ret) {
		printf("Error %d for %s\n", ret, "acreate");
		exit(EXIT_FAILURE);
	}
	
	printf("i'm processing......\n");

	getchar();
	sleep(10);
	zookeeper_close(zkhandle);

}



