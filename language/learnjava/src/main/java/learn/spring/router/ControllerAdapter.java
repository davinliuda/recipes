package learn.spring.router;

import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * Created by liuda on 2017/4/14.
 */
public class ControllerAdapter {

    private ClassPathXmlApplicationContext ctx;

    public ControllerAdapter(){
        ctx = new ClassPathXmlApplicationContext("classpath:spring-application.xml");
    }

    public ApiController getApi(String uri){
        ApiController ac = null;
        if(ctx.containsBean(uri)) {
            ac = ctx.getBean(uri, ApiController.class);
        }
        return ac;
    }


    public static void main(String[] args){

    }
}
