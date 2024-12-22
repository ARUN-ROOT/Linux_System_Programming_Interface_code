/************************************************************************************************************/
/* Name			: publish.c                                      */	   
/* Date			: 3/2/2023                                                                  */
/* Author			: Arun.V                                                                     */
/* Code link			: 									        */ 
/* Descrition			: For more detail below used API function refer 	*/
/*		                 https://mosquitto.org/api/files/mosquitto-h.html                                  */
/* o/p				: 

*/
/************************************************************************************************************/
#include <stdio.h>
#include <mosquitto.h>

int main(){
	int rc;
	struct mosquitto * mosq; 

	mosquitto_lib_init(); //Intilisation

	mosq = mosquitto_new("publishclient-test", true, NULL);//create client instance

	rc = mosquitto_connect(mosq, "localhost", 1883, 60);//connected to localhost , port:1883
	if(rc != 0){
		printf("Client could not connect to broker! Error Code: %d\n", rc);
		mosquitto_destroy(mosq);
		return -1;
	}
	printf(" connected to the broker!\n");
	printf("message sent to broker\n");

	mosquitto_publish(mosq, NULL, "test/topic1", 11, "stellantis", 0, false);//topic: test/topic1,msg:Arun

	mosquitto_disconnect(mosq);
	mosquitto_destroy(mosq);

	mosquitto_lib_cleanup();
	return 0;
}

