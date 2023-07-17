/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __MINIMAL_LEGACY_BPF_SKEL_H__
#define __MINIMAL_LEGACY_BPF_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct minimal_legacy_bpf {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *my_pid_map;
		struct bpf_map *rodata_str1_1;
	} maps;
	struct {
		struct bpf_program *handle_tp;
	} progs;
	struct {
		struct bpf_link *handle_tp;
	} links;
	struct minimal_legacy_bpf__rodata_str1_1 {
	} *rodata_str1_1;
};

static void
minimal_legacy_bpf__destroy(struct minimal_legacy_bpf *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
minimal_legacy_bpf__create_skeleton(struct minimal_legacy_bpf *obj);

static inline struct minimal_legacy_bpf *
minimal_legacy_bpf__open_opts(const struct bpf_object_open_opts *opts)
{
	struct minimal_legacy_bpf *obj;
	int err;

	obj = (struct minimal_legacy_bpf *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = minimal_legacy_bpf__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	minimal_legacy_bpf__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct minimal_legacy_bpf *
minimal_legacy_bpf__open(void)
{
	return minimal_legacy_bpf__open_opts(NULL);
}

static inline int
minimal_legacy_bpf__load(struct minimal_legacy_bpf *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct minimal_legacy_bpf *
minimal_legacy_bpf__open_and_load(void)
{
	struct minimal_legacy_bpf *obj;
	int err;

	obj = minimal_legacy_bpf__open();
	if (!obj)
		return NULL;
	err = minimal_legacy_bpf__load(obj);
	if (err) {
		minimal_legacy_bpf__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
minimal_legacy_bpf__attach(struct minimal_legacy_bpf *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
minimal_legacy_bpf__detach(struct minimal_legacy_bpf *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *minimal_legacy_bpf__elf_bytes(size_t *sz);

static inline int
minimal_legacy_bpf__create_skeleton(struct minimal_legacy_bpf *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "minimal_legacy_bpf";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "my_pid_map";
	s->maps[0].map = &obj->maps.my_pid_map;

	s->maps[1].name = ".rodata.str1.1";
	s->maps[1].map = &obj->maps.rodata_str1_1;
	s->maps[1].mmaped = (void **)&obj->rodata_str1_1;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "handle_tp";
	s->progs[0].prog = &obj->progs.handle_tp;
	s->progs[0].link = &obj->links.handle_tp;

	s->data = (void *)minimal_legacy_bpf__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *minimal_legacy_bpf__elf_bytes(size_t *sz)
{
	*sz = 6664;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x48\x14\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x17\0\
\x01\0\xb7\x01\0\0\0\0\0\0\x63\x1a\xfc\xff\0\0\0\0\x85\0\0\0\x0e\0\0\0\xbf\x06\
\0\0\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x01\0\0\0\0\0\0\xb7\0\0\0\x01\0\0\0\
\x15\x01\x14\0\0\0\0\0\x77\x06\0\0\x20\0\0\0\x61\x11\0\0\0\0\0\0\x5d\x61\x11\0\
\0\0\0\0\xb7\x01\0\0\x64\x2e\x0a\0\x63\x1a\xf8\xff\0\0\0\0\x18\x01\0\0\x6f\x6d\
\x20\x50\0\0\0\0\x49\x44\x20\x25\x7b\x1a\xf0\xff\0\0\0\0\x18\x01\0\0\x67\x65\
\x72\x65\0\0\0\0\x64\x20\x66\x72\x7b\x1a\xe8\xff\0\0\0\0\x18\x01\0\0\x42\x50\
\x46\x20\0\0\0\0\x74\x72\x69\x67\x7b\x1a\xe0\xff\0\0\0\0\xbf\xa1\0\0\0\0\0\0\
\x07\x01\0\0\xe0\xff\xff\xff\xb7\x02\0\0\x1c\0\0\0\xbf\x63\0\0\0\0\0\0\x85\0\0\
\0\x06\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x44\x75\x61\x6c\x20\x42\x53\
\x44\x2f\x47\x50\x4c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x42\x50\x46\x20\x74\x72\x69\x67\x67\x65\x72\x65\x64\x20\x66\x72\
\x6f\x6d\x20\x50\x49\x44\x20\x25\x64\x2e\x0a\0\x63\x6c\x61\x6e\x67\x20\x76\x65\
\x72\x73\x69\x6f\x6e\x20\x31\x30\x2e\x30\x2e\x30\x2d\x34\x75\x62\x75\x6e\x74\
\x75\x31\x20\0\x6d\x69\x6e\x69\x6d\x61\x6c\x5f\x6c\x65\x67\x61\x63\x79\x2e\x62\
\x70\x66\x2e\x63\0\x2f\x68\x6f\x6d\x65\x2f\x73\x74\x65\x76\x65\x70\x72\x6f\x2f\
\x47\x69\x74\x48\x75\x62\x2f\x53\x74\x65\x76\x65\x50\x72\x6f\x39\x2f\x65\x42\
\x50\x46\x74\x65\x73\x74\x69\x6e\x67\x2f\x5f\x53\x65\x74\x75\x70\x49\x56\x2f\
\x30\x37\x2d\x6d\x69\x6e\x69\x6d\x61\x6c\x5f\x6c\x65\x67\x61\x63\x79\0\x4c\x49\
\x43\x45\x4e\x53\x45\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\
\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x6d\x79\x5f\x70\x69\x64\x5f\x6d\x61\
\x70\0\x74\x79\x70\x65\0\x69\x6e\x74\0\x6d\x61\x78\x5f\x65\x6e\x74\x72\x69\x65\
\x73\0\x6b\x65\x79\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x75\x33\
\x32\0\x76\x61\x6c\x75\x65\0\x70\x69\x64\x5f\x74\0\x62\x70\x66\x5f\x67\x65\x74\
\x5f\x63\x75\x72\x72\x65\x6e\x74\x5f\x70\x69\x64\x5f\x74\x67\x69\x64\0\x6c\x6f\
\x6e\x67\x20\x6c\x6f\x6e\x67\x20\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\
\x74\0\x5f\x5f\x75\x36\x34\0\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\
\x75\x70\x5f\x65\x6c\x65\x6d\0\x62\x70\x66\x5f\x74\x72\x61\x63\x65\x5f\x70\x72\
\x69\x6e\x74\x6b\0\x6c\x6f\x6e\x67\x20\x69\x6e\x74\0\x5f\x5f\x75\x33\x32\0\x68\
\x61\x6e\x64\x6c\x65\x5f\x74\x70\0\x5f\x5f\x5f\x5f\x66\x6d\x74\0\x63\x74\x78\0\
\x69\x6e\x64\x65\x78\0\x6d\x79\x5f\x70\x69\x64\0\x70\x69\x64\0\x08\0\0\0\0\0\0\
\0\x20\0\0\0\0\0\0\0\x02\0\x30\x9f\x20\0\0\0\0\0\0\0\x08\x01\0\0\0\0\0\0\x02\0\
\x7a\x1c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\x70\0\0\0\0\0\0\0\
\x01\0\x51\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x68\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\
\x03\0\x76\0\x9f\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\x11\x01\x25\x0e\x13\x05\
\x03\x0e\x10\x17\x1b\x0e\x11\x01\x12\x06\0\0\x02\x34\0\x03\x0e\x49\x13\x3f\x19\
\x3a\x0b\x3b\x0b\x02\x18\0\0\x03\x01\x01\x49\x13\0\0\x04\x21\0\x49\x13\x37\x0b\
\0\0\x05\x24\0\x03\x0e\x3e\x0b\x0b\x0b\0\0\x06\x24\0\x03\x0e\x0b\x0b\x3e\x0b\0\
\0\x07\x13\x01\x0b\x0b\x3a\x0b\x3b\x0b\0\0\x08\x0d\0\x03\x0e\x49\x13\x3a\x0b\
\x3b\x0b\x38\x0b\0\0\x09\x0f\0\x49\x13\0\0\x0a\x16\0\x49\x13\x03\x0e\x3a\x0b\
\x3b\x0b\0\0\x0b\x34\0\x03\x0e\x49\x13\x3a\x0b\x3b\x05\0\0\x0c\x15\0\x49\x13\
\x27\x19\0\0\x0d\x34\0\x03\x0e\x49\x13\x3a\x0b\x3b\x0b\0\0\x0e\x15\x01\x49\x13\
\x27\x19\0\0\x0f\x05\0\x49\x13\0\0\x10\x0f\0\0\0\x11\x26\0\0\0\x12\x18\0\0\0\
\x13\x26\0\x49\x13\0\0\x14\x2e\x01\x11\x01\x12\x06\x40\x18\x97\x42\x19\x03\x0e\
\x3a\x0b\x3b\x0b\x27\x19\x49\x13\x3f\x19\0\0\x15\x05\0\x03\x0e\x3a\x0b\x3b\x0b\
\x49\x13\0\0\x16\x34\0\x02\x17\x03\x0e\x3a\x0b\x3b\x0b\x49\x13\0\0\x17\x0b\x01\
\x11\x01\x12\x06\0\0\x18\x34\0\x02\x18\x03\x0e\x3a\x0b\x3b\x0b\x49\x13\0\0\0\
\xf6\x01\0\0\x04\0\0\0\0\0\x08\x01\0\0\0\0\x0c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x08\x01\0\0\x02\0\0\0\0\x3f\0\0\0\x01\x08\x09\x03\0\0\0\0\0\0\0\0\
\x03\x4b\0\0\0\x04\x52\0\0\0\x0d\0\x05\0\0\0\0\x06\x01\x06\0\0\0\0\x08\x07\x02\
\0\0\0\0\x6e\0\0\0\x01\x11\x09\x03\0\0\0\0\0\0\0\0\x07\x20\x01\x0c\x08\0\0\0\0\
\xa3\0\0\0\x01\x0d\0\x08\0\0\0\0\xbb\0\0\0\x01\x0e\x08\x08\0\0\0\0\xcc\0\0\0\
\x01\x0f\x10\x08\0\0\0\0\xe3\0\0\0\x01\x10\x18\0\x09\xa8\0\0\0\x03\xb4\0\0\0\
\x04\x52\0\0\0\x02\0\x05\0\0\0\0\x05\x04\x09\xc0\0\0\0\x03\xb4\0\0\0\x04\x52\0\
\0\0\x01\0\x09\xd1\0\0\0\x0a\xdc\0\0\0\0\0\0\0\x01\x05\x05\0\0\0\0\x07\x04\x09\
\xe8\0\0\0\x0a\xb4\0\0\0\0\0\0\0\x01\x06\x0b\0\0\0\0\xff\0\0\0\x03\x70\x01\x09\
\x04\x01\0\0\x0c\x09\x01\0\0\x0a\x14\x01\0\0\0\0\0\0\x02\x1f\x05\0\0\0\0\x07\
\x08\x0d\0\0\0\0\x26\x01\0\0\x03\x38\x09\x2b\x01\0\0\x0e\x3b\x01\0\0\x0f\x3b\
\x01\0\0\x0f\x3c\x01\0\0\0\x10\x09\x41\x01\0\0\x11\x0d\0\0\0\0\x4d\x01\0\0\x03\
\xb1\x09\x52\x01\0\0\x0e\x63\x01\0\0\x0f\x6a\x01\0\0\x0f\x74\x01\0\0\x12\0\x05\
\0\0\0\0\x05\x08\x09\x6f\x01\0\0\x13\x4b\0\0\0\x0a\xdc\0\0\0\0\0\0\0\x02\x1b\
\x14\0\0\0\0\0\0\0\0\x08\x01\0\0\x01\x5a\0\0\0\0\x01\x14\xb4\0\0\0\x15\0\0\0\0\
\x01\x14\x3b\x01\0\0\x16\0\0\0\0\0\0\0\0\x01\x16\xd1\0\0\0\x16\x38\0\0\0\0\0\0\
\0\x01\x18\xe3\0\0\0\x16\x5b\0\0\0\0\0\0\0\x01\x17\xe8\0\0\0\x17\x80\0\0\0\0\0\
\0\0\x80\0\0\0\x18\x02\x91\0\0\0\0\0\x01\x1d\xed\x01\0\0\0\0\x03\x4b\0\0\0\x04\
\x52\0\0\0\x1c\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x88\x01\0\0\x88\x01\0\0\xed\
\x01\0\0\0\0\0\0\x04\0\0\x04\x20\0\0\0\x01\0\0\0\x02\0\0\0\0\0\0\0\x06\0\0\0\
\x06\0\0\0\x40\0\0\0\x12\0\0\0\x08\0\0\0\x80\0\0\0\x16\0\0\0\x0b\0\0\0\xc0\0\0\
\0\0\0\0\0\0\0\0\x02\x04\0\0\0\x1c\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\0\0\0\
\0\0\0\0\x03\0\0\0\0\x03\0\0\0\x05\0\0\0\x02\0\0\0\x20\0\0\0\0\0\0\x01\x04\0\0\
\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x07\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x03\0\0\0\
\x05\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x09\0\0\0\x34\0\0\0\0\0\0\x08\x0a\0\0\0\
\x38\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x0c\0\0\0\x45\0\0\0\
\0\0\0\x08\x03\0\0\0\x4b\0\0\0\0\0\0\x0e\x01\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\
\0\0\0\0\0\0\0\0\x01\0\0\x0d\x03\0\0\0\x56\0\0\0\x0e\0\0\0\x5a\0\0\0\x01\0\0\
\x0c\x0f\0\0\0\xd2\x01\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\
\0\0\0\x11\0\0\0\x05\0\0\0\x0d\0\0\0\xd7\x01\0\0\0\0\0\x0e\x12\0\0\0\x01\0\0\0\
\xdf\x01\0\0\x01\0\0\x0f\0\0\0\0\x0d\0\0\0\0\0\0\0\x20\0\0\0\xe5\x01\0\0\x01\0\
\0\x0f\0\0\0\0\x13\0\0\0\0\0\0\0\x0d\0\0\0\0\x74\x79\x70\x65\0\x6d\x61\x78\x5f\
\x65\x6e\x74\x72\x69\x65\x73\0\x6b\x65\x79\0\x76\x61\x6c\x75\x65\0\x69\x6e\x74\
\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\
\0\x75\x33\x32\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x70\x69\x64\
\x5f\x74\0\x6d\x79\x5f\x70\x69\x64\x5f\x6d\x61\x70\0\x63\x74\x78\0\x68\x61\x6e\
\x64\x6c\x65\x5f\x74\x70\0\x74\x70\x2f\x73\x79\x73\x63\x61\x6c\x6c\x73\x2f\x73\
\x79\x73\x5f\x65\x6e\x74\x65\x72\x5f\x77\x72\x69\x74\x65\0\x2f\x68\x6f\x6d\x65\
\x2f\x73\x74\x65\x76\x65\x70\x72\x6f\x2f\x47\x69\x74\x48\x75\x62\x2f\x53\x74\
\x65\x76\x65\x50\x72\x6f\x39\x2f\x65\x42\x50\x46\x74\x65\x73\x74\x69\x6e\x67\
\x2f\x5f\x53\x65\x74\x75\x70\x49\x56\x2f\x30\x37\x2d\x6d\x69\x6e\x69\x6d\x61\
\x6c\x5f\x6c\x65\x67\x61\x63\x79\x2f\x6d\x69\x6e\x69\x6d\x61\x6c\x5f\x6c\x65\
\x67\x61\x63\x79\x2e\x62\x70\x66\x2e\x63\0\x69\x6e\x74\x20\x68\x61\x6e\x64\x6c\
\x65\x5f\x74\x70\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x20\x20\x20\x20\
\x75\x33\x32\x20\x69\x6e\x64\x65\x78\x20\x3d\x20\x30\x3b\0\x20\x20\x20\x20\x70\
\x69\x64\x5f\x74\x20\x70\x69\x64\x20\x3d\x20\x62\x70\x66\x5f\x67\x65\x74\x5f\
\x63\x75\x72\x72\x65\x6e\x74\x5f\x70\x69\x64\x5f\x74\x67\x69\x64\x28\x29\x20\
\x3e\x3e\x20\x33\x32\x3b\0\x20\x20\x20\x20\x70\x69\x64\x5f\x74\x20\x2a\x6d\x79\
\x5f\x70\x69\x64\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\
\x75\x70\x5f\x65\x6c\x65\x6d\x28\x26\x6d\x79\x5f\x70\x69\x64\x5f\x6d\x61\x70\
\x2c\x20\x26\x69\x6e\x64\x65\x78\x29\x3b\0\x20\x20\x20\x20\x69\x66\x20\x28\x21\
\x6d\x79\x5f\x70\x69\x64\x20\x7c\x7c\x20\x2a\x6d\x79\x5f\x70\x69\x64\x20\x21\
\x3d\x20\x70\x69\x64\x29\0\x20\x20\x20\x20\x62\x70\x66\x5f\x70\x72\x69\x6e\x74\
\x6b\x28\x22\x42\x50\x46\x20\x74\x72\x69\x67\x67\x65\x72\x65\x64\x20\x66\x72\
\x6f\x6d\x20\x50\x49\x44\x20\x25\x64\x2e\x5c\x6e\x22\x2c\x20\x70\x69\x64\x29\
\x3b\0\x7d\0\x63\x68\x61\x72\0\x4c\x49\x43\x45\x4e\x53\x45\0\x2e\x6d\x61\x70\
\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\
\x14\0\0\0\xbc\0\0\0\xd0\0\0\0\0\0\0\0\x08\0\0\0\x64\0\0\0\x01\0\0\0\0\0\0\0\
\x10\0\0\0\x10\0\0\0\x64\0\0\0\x0b\0\0\0\0\0\0\0\x80\0\0\0\xdc\0\0\0\0\x50\0\0\
\x08\0\0\0\x80\0\0\0\xf5\0\0\0\x09\x58\0\0\x10\0\0\0\x80\0\0\0\x08\x01\0\0\x11\
\x5c\0\0\x28\0\0\0\x80\0\0\0\0\0\0\0\0\0\0\0\x30\0\0\0\x80\0\0\0\x3a\x01\0\0\
\x15\x60\0\0\x58\0\0\0\x80\0\0\0\x78\x01\0\0\x11\x68\0\0\x60\0\0\0\x80\0\0\0\0\
\0\0\0\0\0\0\0\x68\0\0\0\x80\0\0\0\x78\x01\0\0\x14\x68\0\0\x70\0\0\0\x80\0\0\0\
\x78\x01\0\0\x09\x68\0\0\x80\0\0\0\x80\0\0\0\x9b\x01\0\0\x05\x74\0\0\0\x01\0\0\
\x80\0\0\0\xd0\x01\0\0\x01\x80\0\0\0\0\0\0\0\0\0\x0c\0\0\0\xff\xff\xff\xff\x04\
\0\x08\0\x08\x7c\x0b\0\x14\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\x01\0\0\0\0\0\0\
\xce\0\0\0\x04\0\x79\0\0\0\x08\x01\x01\xfb\x0e\x0d\0\x01\x01\x01\x01\0\0\0\x01\
\0\0\x01\x2f\x75\x73\x72\x2f\x69\x6e\x63\x6c\x75\x64\x65\x2f\x61\x73\x6d\x2d\
\x67\x65\x6e\x65\x72\x69\x63\0\x2f\x75\x73\x72\x2f\x69\x6e\x63\x6c\x75\x64\x65\
\x2f\x62\x70\x66\0\0\x6d\x69\x6e\x69\x6d\x61\x6c\x5f\x6c\x65\x67\x61\x63\x79\
\x2e\x62\x70\x66\x2e\x63\0\0\0\0\x69\x6e\x74\x2d\x6c\x6c\x36\x34\x2e\x68\0\x01\
\0\0\x62\x70\x66\x5f\x68\x65\x6c\x70\x65\x72\x5f\x64\x65\x66\x73\x2e\x68\0\x02\
\0\0\0\0\x09\x02\0\0\0\0\0\0\0\0\x03\x14\x01\x05\x09\x0a\x21\x05\x11\x21\x06\
\x03\x69\x2e\x05\x15\x06\x03\x18\x2e\x06\x03\x68\x4a\x05\x11\x06\x03\x1a\x20\
\x05\0\x06\x03\x66\x20\x05\x14\x03\x1a\x20\x05\x09\x20\x03\x66\x20\x05\x05\x06\
\x03\x1d\x20\x06\x03\x63\xe4\x05\x01\x06\x03\x20\x20\x02\x01\0\x01\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xba\0\0\0\x04\0\xf1\xff\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x08\0\x1f\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\x34\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\x7b\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x08\0\x83\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\x88\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\x9c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x08\0\xa7\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\xac\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\xb0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x08\0\xbc\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\xc0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\xcd\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x08\0\xd1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\xd7\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\xdd\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x08\0\xf6\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\x0d\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\x13\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x08\0\x27\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\
\0\x38\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\x41\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\x47\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x08\0\x51\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\x59\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\x5d\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x08\0\x63\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\x6a\x01\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\xf0\0\0\0\0\0\x03\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x09\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x0a\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x03\0\x11\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x13\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe8\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x0d\0\0\0\0\
\0\0\0\x33\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x08\x01\0\0\0\0\0\0\x3d\0\0\0\x11\
\0\x06\0\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\x01\0\0\0\x26\0\0\
\0\x06\0\0\0\0\0\0\0\x0a\0\0\0\x21\0\0\0\x0c\0\0\0\0\0\0\0\x0a\0\0\0\x02\0\0\0\
\x12\0\0\0\0\0\0\0\x0a\0\0\0\x03\0\0\0\x16\0\0\0\0\0\0\0\x0a\0\0\0\x23\0\0\0\
\x1a\0\0\0\0\0\0\0\x0a\0\0\0\x04\0\0\0\x1e\0\0\0\0\0\0\0\x01\0\0\0\x1f\0\0\0\
\x2b\0\0\0\0\0\0\0\x0a\0\0\0\x05\0\0\0\x37\0\0\0\0\0\0\0\x01\0\0\0\x24\0\0\0\
\x4c\0\0\0\0\0\0\0\x0a\0\0\0\x06\0\0\0\x53\0\0\0\0\0\0\0\x0a\0\0\0\x07\0\0\0\
\x5a\0\0\0\0\0\0\0\x0a\0\0\0\x08\0\0\0\x66\0\0\0\0\0\0\0\x01\0\0\0\x26\0\0\0\
\x73\0\0\0\0\0\0\0\x0a\0\0\0\x09\0\0\0\x7f\0\0\0\0\0\0\0\x0a\0\0\0\x0b\0\0\0\
\x8b\0\0\0\0\0\0\0\x0a\0\0\0\x0c\0\0\0\x97\0\0\0\0\0\0\0\x0a\0\0\0\x0f\0\0\0\
\xb5\0\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\xd6\0\0\0\0\0\0\0\x0a\0\0\0\x0e\0\0\0\
\xdd\0\0\0\0\0\0\0\x0a\0\0\0\x0d\0\0\0\xed\0\0\0\0\0\0\0\x0a\0\0\0\x10\0\0\0\
\xf4\0\0\0\0\0\0\0\x0a\0\0\0\x11\0\0\0\x0e\x01\0\0\0\0\0\0\x0a\0\0\0\x13\0\0\0\
\x15\x01\0\0\0\0\0\0\x0a\0\0\0\x12\0\0\0\x1c\x01\0\0\0\0\0\0\x0a\0\0\0\x14\0\0\
\0\x43\x01\0\0\0\0\0\0\x0a\0\0\0\x15\0\0\0\x64\x01\0\0\0\0\0\0\x0a\0\0\0\x16\0\
\0\0\x79\x01\0\0\0\0\0\0\x0a\0\0\0\x17\0\0\0\x80\x01\0\0\0\0\0\0\x01\0\0\0\x1f\
\0\0\0\x8e\x01\0\0\0\0\0\0\x0a\0\0\0\x18\0\0\0\x99\x01\0\0\0\0\0\0\x0a\0\0\0\
\x1a\0\0\0\xa4\x01\0\0\0\0\0\0\x0a\0\0\0\x20\0\0\0\xa8\x01\0\0\0\0\0\0\x0a\0\0\
\0\x1b\0\0\0\xb3\x01\0\0\0\0\0\0\x0a\0\0\0\x20\0\0\0\xb7\x01\0\0\0\0\0\0\x0a\0\
\0\0\x1c\0\0\0\xc2\x01\0\0\0\0\0\0\x0a\0\0\0\x20\0\0\0\xc6\x01\0\0\0\0\0\0\x0a\
\0\0\0\x1d\0\0\0\xd1\x01\0\0\0\0\0\0\x01\0\0\0\x1f\0\0\0\xe1\x01\0\0\0\0\0\0\
\x0a\0\0\0\x19\0\0\0\x80\x01\0\0\0\0\0\0\0\0\0\0\x26\0\0\0\x98\x01\0\0\0\0\0\0\
\0\0\0\0\x24\0\0\0\x2c\0\0\0\0\0\0\0\0\0\0\0\x1f\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\
\0\x1f\0\0\0\x50\0\0\0\0\0\0\0\0\0\0\0\x1f\0\0\0\x60\0\0\0\0\0\0\0\0\0\0\0\x1f\
\0\0\0\x70\0\0\0\0\0\0\0\0\0\0\0\x1f\0\0\0\x80\0\0\0\0\0\0\0\0\0\0\0\x1f\0\0\0\
\x90\0\0\0\0\0\0\0\0\0\0\0\x1f\0\0\0\xa0\0\0\0\0\0\0\0\0\0\0\0\x1f\0\0\0\xb0\0\
\0\0\0\0\0\0\0\0\0\0\x1f\0\0\0\xc0\0\0\0\0\0\0\0\0\0\0\0\x1f\0\0\0\xd0\0\0\0\0\
\0\0\0\0\0\0\0\x1f\0\0\0\xe0\0\0\0\0\0\0\0\0\0\0\0\x1f\0\0\0\x14\0\0\0\0\0\0\0\
\x0a\0\0\0\x22\0\0\0\x18\0\0\0\0\0\0\0\x01\0\0\0\x1f\0\0\0\x86\0\0\0\0\0\0\0\
\x01\0\0\0\x1f\0\0\0\x25\x24\x26\0\x2e\x64\x65\x62\x75\x67\x5f\x61\x62\x62\x72\
\x65\x76\0\x2e\x74\x65\x78\x74\0\x2e\x72\x65\x6c\x2e\x42\x54\x46\x2e\x65\x78\
\x74\0\x2e\x6d\x61\x70\x73\0\x2e\x64\x65\x62\x75\x67\x5f\x73\x74\x72\0\x68\x61\
\x6e\x64\x6c\x65\x5f\x74\x70\0\x6d\x79\x5f\x70\x69\x64\x5f\x6d\x61\x70\0\x2e\
\x72\x65\x6c\x2e\x64\x65\x62\x75\x67\x5f\x69\x6e\x66\x6f\0\x2e\x6c\x6c\x76\x6d\
\x5f\x61\x64\x64\x72\x73\x69\x67\0\x2e\x72\x65\x6c\x74\x70\x2f\x73\x79\x73\x63\
\x61\x6c\x6c\x73\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\x5f\x77\x72\x69\x74\
\x65\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x2e\x64\x65\x62\x75\x67\
\x5f\x6c\x69\x6e\x65\0\x2e\x72\x65\x6c\x2e\x64\x65\x62\x75\x67\x5f\x66\x72\x61\
\x6d\x65\0\x2e\x64\x65\x62\x75\x67\x5f\x6c\x6f\x63\0\x6d\x69\x6e\x69\x6d\x61\
\x6c\x5f\x6c\x65\x67\x61\x63\x79\x2e\x62\x70\x66\x2e\x63\0\x2e\x73\x74\x72\x74\
\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x72\x65\x6c\x2e\x42\x54\x46\0\x4c\
\x49\x43\x45\x4e\x53\x45\0\x4c\x42\x42\x30\x5f\x33\0\x2e\x72\x6f\x64\x61\x74\
\x61\x2e\x73\x74\x72\x31\x2e\x31\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\xcf\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x3b\
\x13\0\0\0\0\0\0\x06\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x0f\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x6a\0\0\0\
\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x08\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x66\0\0\0\x09\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb8\x0f\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x16\0\0\0\
\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x86\0\0\0\x01\0\0\0\x03\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x48\x01\0\0\0\0\0\0\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x22\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x58\x01\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\xf7\0\0\0\x01\0\0\0\x32\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x78\
\x01\0\0\0\0\0\0\x1c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x01\0\0\0\
\0\0\0\0\x28\0\0\0\x01\0\0\0\x30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x94\x01\0\0\0\0\
\0\0\x6e\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\
\xaf\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x03\0\0\0\0\0\0\x80\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x01\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x82\x03\0\0\0\0\0\0\x10\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4c\0\0\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x92\x04\0\0\0\0\0\0\xfa\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x48\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xc8\x0f\0\0\0\0\0\0\x60\x02\0\0\0\0\0\0\x16\0\0\0\x0b\0\0\0\x08\0\0\0\
\0\0\0\0\x10\0\0\0\0\0\0\0\xe3\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x8c\x06\0\0\0\0\0\0\x8d\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\xdf\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\x12\0\0\0\
\0\0\0\x20\0\0\0\0\0\0\0\x16\0\0\0\x0d\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\
\0\x19\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x19\x0a\0\0\0\0\0\0\xf0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x15\0\0\0\x09\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x48\x12\0\0\0\0\0\0\xc0\0\0\0\0\0\0\0\
\x16\0\0\0\x0f\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xa2\0\0\0\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\x0b\0\0\0\0\0\0\x28\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9e\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x08\x13\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x16\0\0\0\x11\0\0\0\x08\0\
\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x92\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x38\x0b\0\0\0\0\0\0\xd2\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x8e\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\x13\0\0\
\0\0\0\0\x10\0\0\0\0\0\0\0\x16\0\0\0\x13\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\
\0\0\x58\0\0\0\x03\x4c\xff\x6f\0\0\0\x80\0\0\0\0\0\0\0\0\0\0\0\0\x38\x13\0\0\0\
\0\0\0\x03\0\0\0\0\0\0\0\x16\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\xd7\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\x0c\0\0\0\0\0\0\xa8\
\x03\0\0\0\0\0\0\x01\0\0\0\x24\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0";
}

#endif /* __MINIMAL_LEGACY_BPF_SKEL_H__ */