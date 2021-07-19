set(SRC_SERVER_TMP
        ${REDIS_ROOT}/src/crcspeed.c
        ${REDIS_ROOT}/src/crcspeed.h
        ${REDIS_ROOT}/src/sha256.c
        ${REDIS_ROOT}/src/sha256.h
        ${REDIS_ROOT}/src/connection.c
        ${REDIS_ROOT}/src/connection.h
        ${REDIS_ROOT}/src/acl.c
        ${REDIS_ROOT}/src/timeout.c
        ${REDIS_ROOT}/src/tracking.c
        ${REDIS_ROOT}/src/tls.c
        ${REDIS_ROOT}/src/adlist.c
        ${REDIS_ROOT}/src/ae.c
        ${REDIS_ROOT}/src/anet.c
        ${REDIS_ROOT}/src/dict.c
        ${REDIS_ROOT}/src/sds.c
        ${REDIS_ROOT}/src/zmalloc.c
        ${REDIS_ROOT}/src/lzf_c.c
        ${REDIS_ROOT}/src/lzf_d.c
        ${REDIS_ROOT}/src/pqsort.c
        ${REDIS_ROOT}/src/zipmap.c
        ${REDIS_ROOT}/src/sha1.c
        ${REDIS_ROOT}/src/ziplist.c
        ${REDIS_ROOT}/src/release.c
        ${REDIS_ROOT}/src/networking.c
        ${REDIS_ROOT}/src/util.c
        ${REDIS_ROOT}/src/object.c
        ${REDIS_ROOT}/src/db.c
        ${REDIS_ROOT}/src/replication.c
        ${REDIS_ROOT}/src/rdb.c
        ${REDIS_ROOT}/src/t_string.c
        ${REDIS_ROOT}/src/t_list.c
        ${REDIS_ROOT}/src/t_set.c
        ${REDIS_ROOT}/src/t_zset.c
        ${REDIS_ROOT}/src/evict.c
        ${REDIS_ROOT}/src/defrag.c
        ${REDIS_ROOT}/src/module.c
        ${REDIS_ROOT}/src/quicklist.c
        ${REDIS_ROOT}/src/expire.c
        ${REDIS_ROOT}/src/childinfo.c
        ${REDIS_ROOT}/src/redis-check-aof.c
        ${REDIS_ROOT}/src/redis-check-rdb.c
        ${REDIS_ROOT}/src/lazyfree.c
        ${REDIS_ROOT}/src/geohash.c
        ${REDIS_ROOT}/src/rax.c
        ${REDIS_ROOT}/src/geohash_helper.c
        ${REDIS_ROOT}/src/siphash.c
        ${REDIS_ROOT}/src/geo.c
        ${REDIS_ROOT}/src/t_hash.c
        ${REDIS_ROOT}/src/config.c
        ${REDIS_ROOT}/src/aof.c
        ${REDIS_ROOT}/src/pubsub.c
        ${REDIS_ROOT}/src/multi.c
        ${REDIS_ROOT}/src/debug.c
        ${REDIS_ROOT}/src/sort.c
        ${REDIS_ROOT}/src/intset.c
        ${REDIS_ROOT}/src/syncio.c
        ${REDIS_ROOT}/src/cluster.c
        ${REDIS_ROOT}/src/crc16.c
        ${REDIS_ROOT}/src/endianconv.c
        ${REDIS_ROOT}/src/slowlog.c
        ${REDIS_ROOT}/src/scripting.c
        ${REDIS_ROOT}/src/bio.c
        ${REDIS_ROOT}/src/rio.c
        ${REDIS_ROOT}/src/rand.c
        ${REDIS_ROOT}/src/memtest.c
        ${REDIS_ROOT}/src/crc64.c
        ${REDIS_ROOT}/src/bitops.c
        ${REDIS_ROOT}/src/sentinel.c
        ${REDIS_ROOT}/src/notify.c
        ${REDIS_ROOT}/src/setproctitle.c
        ${REDIS_ROOT}/src/blocked.c
        ${REDIS_ROOT}/src/hyperloglog.c
        ${REDIS_ROOT}/src/latency.c
        ${REDIS_ROOT}/src/sparkline.c
        ${REDIS_ROOT}/src/t_stream.c
        ${REDIS_ROOT}/src/lolwut.c
        ${REDIS_ROOT}/src/lolwut.h
        ${REDIS_ROOT}/src/lolwut5.c
        ${REDIS_ROOT}/src/lolwut6.c
        ${REDIS_ROOT}/src/listpack.c
        ${REDIS_ROOT}/src/localtime.c
        ${REDIS_ROOT}/src/gopher.c
        ${REDIS_ROOT}/src/server-test.c
        )

set(dict_test_dir dict_test.c ${SRC_SERVER_TMP})


ADD_EXECUTABLE(dict_test ${dict_test_dir})


target_include_directories(dict_test
        PRIVATE ${REDIS_ROOT}/deps/hiredis
        PRIVATE ${REDIS_ROOT}/deps/linenoise
        PRIVATE ${REDIS_ROOT}/deps/lua/src
        )


target_link_libraries(dict_test
        PRIVATE lua
        PRIVATE linenoise
        PRIVATE hiredis
        )




set(skip_test_dir skip_test.c ${SRC_SERVER_TMP})


ADD_EXECUTABLE(skip_test ${skip_test_dir})


target_include_directories(skip_test
        PRIVATE ${REDIS_ROOT}/deps/hiredis
        PRIVATE ${REDIS_ROOT}/deps/linenoise
        PRIVATE ${REDIS_ROOT}/deps/lua/src
        )


target_link_libraries(skip_test
        PRIVATE lua
        PRIVATE linenoise
        PRIVATE hiredis
        )



ADD_EXECUTABLE(fork_test fork_test.c)