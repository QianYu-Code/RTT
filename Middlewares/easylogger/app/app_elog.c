#include "app_elog.h"

#include "elog.h"
#include "stdio.h"

void app_elog_init(void)
{
    elog_init(); //   初始化elog
    elog_set_text_color_enabled(true);//打开日志颜色
    
    /* set EasyLogger log format */
    elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_ERROR, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_WARN, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL & ~ELOG_FMT_FUNC);
    elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL & ~ELOG_FMT_FUNC);
    /* start EasyLogger */
    elog_start();
    
}

void test_elog(void)
{
    log_a("this is assert");
    log_e("this is error");
    log_w("this is warning");
    log_i("this is info");
    log_d("this is debug");
    log_v("this is verbose");
}
