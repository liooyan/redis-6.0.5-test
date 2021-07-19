
set(SRC_SERVER_TMP
         crcspeed.c
         crcspeed.h
         sha256.c
         sha256.h
         connection.c
         connection.h
         acl.c
         timeout.c
         tracking.c
         tls.c
         adlist.c
         ae.c
         anet.c
         dict.c
         sds.c
         zmalloc.c
         lzf_c.c
         lzf_d.c
         pqsort.c
         zipmap.c
         sha1.c
         ziplist.c
         release.c
         networking.c
         util.c
         object.c
         db.c
         replication.c
         rdb.c
         t_string.c
         t_list.c
         t_set.c
         t_zset.c
         evict.c
         defrag.c
         module.c
         quicklist.c
         expire.c
         childinfo.c
         redis-check-aof.c
         redis-check-rdb.c
         lazyfree.c
         geohash.c
         rax.c
         geohash_helper.c
         siphash.c
         geo.c
         t_hash.c
         config.c
         aof.c
         pubsub.c
         multi.c
         debug.c
         sort.c
         intset.c
         syncio.c
         cluster.c
         crc16.c
         endianconv.c
         slowlog.c
         scripting.c
         bio.c
         rio.c
         rand.c
         memtest.c
         crc64.c
         bitops.c
         sentinel.c
         notify.c
         setproctitle.c
         blocked.c
         hyperloglog.c
         latency.c
         sparkline.c
         t_stream.c
         lolwut.c
         lolwut.h
         lolwut5.c
         lolwut6.c
         listpack.c
         localtime.c
         gopher.c
        )

set(SRC_SERVER  server.c ${SRC_SERVER_TMP})

set(SRC_CLI
         anet.c  sds.c  adlist.c  redis-cli.c  zmalloc.c  release.c  anet.c  ae.c  crc64.c
        )

add_executable(redis-cli ${SRC_CLI})


add_executable(redis-server ${SRC_SERVER})
target_include_directories(redis-server
        PRIVATE ${REDIS_ROOT}/deps/hiredis
        PRIVATE ${REDIS_ROOT}/deps/linenoise
        PRIVATE ${REDIS_ROOT}/deps/lua/src
        )

target_link_libraries(redis-server
        PRIVATE lua
        PRIVATE linenoise
        PRIVATE hiredis
        )

target_include_directories(redis-cli
        PRIVATE ${REDIS_ROOT}/deps/hiredis
        PRIVATE ${REDIS_ROOT}/deps/linenoise
        PRIVATE ${REDIS_ROOT}/deps/lua/src
        )




# 用于做主从分布式
add_executable(redis-server-slave-1 ${SRC_SERVER})
target_include_directories(redis-server-slave-1
        PRIVATE ${REDIS_ROOT}/deps/hiredis
        PRIVATE ${REDIS_ROOT}/deps/linenoise
        PRIVATE ${REDIS_ROOT}/deps/lua/src
        )

target_link_libraries(redis-server-slave-1
        PRIVATE lua
        PRIVATE linenoise
        PRIVATE hiredis
        )

add_executable(redis-server-slave-2 ${SRC_SERVER})
target_include_directories(redis-server-slave-2
        PRIVATE ${REDIS_ROOT}/deps/hiredis
        PRIVATE ${REDIS_ROOT}/deps/linenoise
        PRIVATE ${REDIS_ROOT}/deps/lua/src
        )

target_link_libraries(redis-server-slave-2
        PRIVATE lua
        PRIVATE linenoise
        PRIVATE hiredis
        )


add_executable(redis-server-slave-3 ${SRC_SERVER})
target_include_directories(redis-server-slave-3
        PRIVATE ${REDIS_ROOT}/deps/hiredis
        PRIVATE ${REDIS_ROOT}/deps/linenoise
        PRIVATE ${REDIS_ROOT}/deps/lua/src
        )

target_link_libraries(redis-server-slave-3
        PRIVATE lua
        PRIVATE linenoise
        PRIVATE hiredis
        )