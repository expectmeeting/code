/*************************************************************************
    > File Name: test.h
    > Author: DHD
    > Mail: 
    > Created Time: 2020年10月28日 星期三 22时47分28秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#undef TRACE_SYSTEM
#define TRACE_SYSTEM test

#if !defined(_TRACE_TEST_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_TEST_H

#include <linux/tracepoint.h>

DECLARE_TRACE(test_test,
		    TP_PROTO(int firstarg, int p),
			    TP_ARGS(firstarg, p));

#endif /* _TRACE_SUBSYS_H */

/* This part must be outside protection */
#include <trace/define_trace.h>

#endif
