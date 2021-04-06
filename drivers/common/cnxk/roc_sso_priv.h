/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(C) 2021 Marvell.
 */

#ifndef _ROC_SSO_PRIV_H_
#define _ROC_SSO_PRIV_H_

struct sso_rsrc {
	uint16_t rsrc_id;
	uint64_t base;
};

struct sso {
	struct plt_pci_device *pci_dev;
	struct dev dev;
	/* SSO link mapping. */
	struct plt_bitmap **link_map;
	void *link_map_mem;
} __plt_cache_aligned;

enum sso_err_status {
	SSO_ERR_PARAM = -4096,
};

enum sso_lf_type {
	SSO_LF_TYPE_HWS,
	SSO_LF_TYPE_HWGRP,
};

static inline struct sso *
roc_sso_to_sso_priv(struct roc_sso *roc_sso)
{
	return (struct sso *)&roc_sso->reserved[0];
}

#endif /* _ROC_SSO_PRIV_H_ */