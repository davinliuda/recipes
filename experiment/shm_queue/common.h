
enum
{
	success = 0,
	fail = 1,

	error = -1,

	queue_buffer_is_not_enough = 2,   /**< 队列空间不够*/
	queue_is_empty			   = 3,   /**< 队列为空*/


};

enum //seconds in xxx
{
	MINUTE = 60, //one minute
	HOUR   = 60*MINUTE, //one hour
	DAY	   = 24*HOUR,	//one day
	YEAR   = 365*DAY	//one year
};
