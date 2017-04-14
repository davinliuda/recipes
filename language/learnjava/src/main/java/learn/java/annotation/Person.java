package learn.java.annotation;

import java.lang.annotation.*;

/**
 * Created by liuda on 2017/4/13.
 */


/*
* */

@Inherited //注解可以继承
@Retention(RetentionPolicy.RUNTIME) //class runtime source三种类型。注解将在哪个地方可用
@Target(ElementType.TYPE) //注解，决定了加在哪个上面
@interface Person {
    String property() default "i'm liuda";
}
